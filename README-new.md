# Hakoniwa ROS2 PDU Generator (詳細ドキュメント)

このドキュメントは、`hakoniwa-ros2pdu`リポジトリの設計思想、内部仕様、および高度な利用方法について詳述するものです。

## 1. 設計思想 (Architecture)

このジェネレータは、異なる言語や環境で動作するシミュレーションアセット間の相互運用性を最大化することを目的として、明確な関心の分離に基づいています。

- **PDU (C互換型)**: `Hako_*` という接頭辞を持つC言語の構造体です。共有メモリ上で直接交換される、固定的かつ言語非依存のメモリレイアウトを持ちます。これが、すべての通信の基礎となる「正」のデータ表現です。

- **Hakoniwa C++型**: `HakoCpp_*` という接頭辞を持つC++の構造体です。`std::vector`や`std::string`を利用でき、C++開発者にとって直感的で扱いやすい型です。この型はROS 2のライブラリに依存しないため、ROS 2がインストールされていない環境（例: MuJoCo連携アセット）でも利用できます。

- **ROS 2 C++型**: ROS 2ノードで標準的に使われるメッセージ型です。

- **Python型**: Python開発者のために生成される、型ヒント付きの純粋なPythonクラスです。`list`や`str`などのネイティブなデータ型を使用し、直感的な開発体験を提供します。

変換は、これらの型の間で段階的に行われます。例えば、ROS 2からPDUへの変換は `ROS 2 C++型 -> PDU`、MuJoCoアセットの場合は `MuJoCo独自型 -> Hakoniwa C++型 -> PDU` のように、各コンポーネントが自身の責務に集中できる設計になっています。

## 2. PDUバイナリ仕様

HakoniwaのPDUは、以下のバイナリ構造を持ちます。エンディアンはリトルエンディアン (`<`) です。

```
[ PDU MetaData ] [ Padding ] [ BaseData ] [ Padding ] [ HeapData ]
```

### 2.1. MetaData (20バイト)

PDU全体の情報を保持するヘッダです。

| Offset | 型      | 内容                                   |
|--------|---------|----------------------------------------|
| 0      | `uint32`| マジックナンバー (リトルエンディアンで `0x12345678`) |
| 4      | `uint32`| PDU仕様のバージョン (現在は `1`)         |
| 8      | `uint32`| `BaseData` の開始オフセット (通常は24)   |
| 12     | `uint32`| `HeapData` の開始オフセット              |
| 16     | `uint32`| PDU全体の合計サイズ (バイト単位)       |

### 2.2. BaseData

C言語の構造体定義そのものであり、固定長のデータが格納されます。アライメント要件に従って、フィールド間にパディングが挿入されることがあります。

- **プリミティブ型**: `int32`, `float64` などの値が直接格納されます。
- **固定長配列**: 要素が連続して格納されます。
- **可変長データへの参照**: 文字列や可変長配列などの可変長データは`HeapData`に実体を置きます。`BaseData`には、その実体への参照情報（8バイト）が格納されます。

#### 可変長データの参照構造 (8バイト)

| Offset | 型      | 内容                                   |
|--------|---------|----------------------------------------|
| 0      | `int32` | `HeapData`内の要素数                   |
| 4      | `int32` | `HeapData`の先頭からのオフセット(バイト単位) |

### 2.3. HeapData

`BaseData`から参照される可変長のデータ（文字列、配列など）の実体が、パディングなしで密に格納されます。

## 3. PDU生成ワークフロー

`python3 -m utils.hakoniwa_pdu_generator.main <メッセージリストファイル>` を実行すると、以下のワークフローでPDU関連ファイルが生成されます。

1.  **依存関係解決**: 指定されたROSメッセージリストを元に、すべての依存メッセージを再帰的に解決します。
2.  **多言語の型定義生成**: 依存関係に基づき、C/C++, C#, Pythonの型定義ファイル（`pdu_ctype_*.h`, `pdu_pytype_*.py`など）を生成します。
3.  **オフセット計算**: C++コンパイラを内部的に使用し、`BaseData`の正確なメモリレイアウト（各メンバーのオフセット、サイズ、パディング）を計算し、`pdu/offset/`ディレクトリに**オフセットファイル**を生成します。
4.  **Pythonコンバータ生成**: ステップ3で生成された**オフセットファイル**を「設計図」として、Pythonのシリアライザ/デシリアライザ (`pdu_conv_*.py`) を生成します。これにより、Python実装はC++のメモリレイアウトと完全に一致することが保証されます。

## 4. Python PDUサポートの使い方

生成されたPythonファイルは、以下の役割を持ちます。

- `pdu/python/pdu_utils.py`: PDUのメタデータ定義やシリアライズ/デシリアライズの共通処理をまとめたライブラリ。
- `pdu/python/{pkg}/pdu_pytype_{msg}.py`: `int`や`list`など、Pythonのネイティブな型で構成された、扱いやすいデータクラス。
- `pdu/python/{pkg}/pdu_conv_{msg}.py`: PDUのバイト列とPythonデータクラスとの間で相互変換を行うための関数 `pdu_to_py_*` と `py_to_pdu_*` を提供します。

### 使用例

```python
import sys
import os

# プロジェクトルートをPYTHONPATHに追加
sys.path.append('/path/to/hakoniwa-ros2pdu')

from pdu.python.geometry_msgs.pdu_pytype_Point import Point
from pdu.python.geometry_msgs.pdu_conv_Point import py_to_pdu_Point, pdu_to_py_Point

# 1. Pythonオブジェクトを作成
my_point = Point()
my_point.x = 1.23
my_point.y = 4.56
my_point.z = 7.89

# 2. PDUバイト列にシリアライズ
pdu_bytes = py_to_pdu_Point(my_point)

# 3. PDUバイト列からPythonオブジェクトにデシリアライズ
reconstructed_point = pdu_to_py_Point(pdu_bytes)

print(f"Original:      {my_point}")
print(f"Reconstructed: {reconstructed_point}")
assert abs(my_point.z - reconstructed_point.z) < 1e-9
```

## 5. テスト

C++とPython間のクロス言語互換性を検証するためのテストスイートが用意されています。

### 実行方法

プロジェクトのルートディレクトリで以下のコマンドを実行するだけで、C++テストプログラムのビルドから、PDUファイルの相互生成・検証まで、すべてが自動的に行われます。

```bash
./run_tests.bash
```

### テストフロー

1.  **C++ビルド**: `workspace/test/cpp` にあるC++テストプログラム (`pdu_tester`) をCMakeでビルドします。
2.  **Python -> C++**: Pythonスクリプトが `point_from_py.pdu` を生成し、C++の `pdu_tester` がそれを読み込んで内容を検証します。
3.  **C++ -> Python**: C++の `pdu_tester` が `point_from_cpp.pdu` を生成し、Pythonスクリプトがそれを読み込んで内容を検証します。

すべてのテストが成功すれば、PDUの相互変換に完全な互換性があることが証明されます。
