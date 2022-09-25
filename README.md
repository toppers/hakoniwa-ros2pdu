# hakoniwa-ros2pdu
C++版箱庭コア機能上で動作するアセット同士はPDUというデータ単位で通信します。
PDUデータのデータ型は、C言語の構造体であり、ROS2メッセージの定義データ(msgファイル)を入力にして自動生成されます。
PDUデータ型を自動生成するための環境として、docker 環境を用意しています。

## インストール手順

```
git clone https://github.com/toppers/hakoniwa-ros2pdu.git
```

```
bash docker/create_image.bash
```

## 前準備
以下の２ファイルの設定をします。

* config/ros_msgs.txt
  * 生成したいPDUのデータ型の名前(ROSメッセージデータ型名を指定する)
* search_path.txt
  * ROSメッセージデータ型が配置されているファイルパスを指定

### 設定例(config/ros_msgs.txt)

```
can_msgs/HakoCan
ev3_msgs/EV3PduSensor
ev3_msgs/EV3PduActuator
```

### 設定例(config/search_path.txt)

```
/opt/ros/foxy/share
/root/workspace/hakoniwa-ros2pdu/workspace/src
```

## PDUデータ型作成方法

```
bash docker/run.bash
```

```
bash create_all_pdus.bash 
```

成功すると以下のメッセージが出力されます。

```
#### Creating can_msgs/HakoCan ####
#### Creating can_msgs/HakoCanBody ####
#### Creating can_msgs/HakoCanHead ####
#### Creating ev3_msgs/EV3PduSensor ####
#### Creating ev3_msgs/Ev3PduColorSensor ####
#### Creating ev3_msgs/Ev3PduSensorHeader ####
#### Creating ev3_msgs/Ev3PduTouchSensor ####
#### Creating ev3_msgs/EV3PduActuator ####
#### Creating ev3_msgs/Ev3PduActuatorHeader ####
#### Creating ev3_msgs/Ev3PduMotor ####
```

構造体は、`pdu/types`配下に生成されます。

```
pdu/types
├── can_msgs
│   ├── pdu_ctype_HakoCan.h
│   ├── pdu_ctype_HakoCanBody.h
│   └── pdu_ctype_HakoCanHead.h
├── ev3_msgs
│   ├── pdu_ctype_EV3PduActuator.h
│   ├── pdu_ctype_EV3PduSensor.h
│   ├── pdu_ctype_Ev3PduActuatorHeader.h
│   ├── pdu_ctype_Ev3PduColorSensor.h
│   ├── pdu_ctype_Ev3PduMotor.h
│   ├── pdu_ctype_Ev3PduSensorHeader.h
│   └── pdu_ctype_Ev3PduTouchSensor.h
└── pdu_primitive_ctypes.h
```



