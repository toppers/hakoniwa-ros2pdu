import fs from 'fs';
import path from 'path';
import { pathToFileURL } from 'url';

// This script is run from the project root.
async function runTest() {
  if (process.argv.length < 7) {
    console.error('Usage: node <script> <pkg> <msg> <in_json> <in_bin> <out_bin>');
    process.exit(1);
  }

  const packageName = process.argv[2];
  const messageName = process.argv[3];
  const jsonInputFile = process.argv[4];
  const binaryInputFile = process.argv[5];
  const binaryOutputFile = process.argv[6];

  try {
    // --- Load converter module robustly (absolute path -> file:// URL) ---
    const convModulePath = path.resolve('pdu', 'javascript', packageName, `pdu_conv_${messageName}.js`);
    const convModuleUrl = pathToFileURL(convModulePath).href;
    const convModule = await import(convModuleUrl);

    // --- Pick converter functions ---
    const pduToJsName = `pduToJs_${messageName}`;
    const jsToPduName = `jsToPdu_${messageName}`;
    const pduToJs = convModule[pduToJsName];
    const jsToPdu = convModule[jsToPduName];

    if (typeof pduToJs !== 'function' || typeof jsToPdu !== 'function') {
      throw new Error(`Converter functions not found in ${convModulePath}`);
    }

    // --- 1) Deserialization ---
    console.log(` -> Deserializing ${binaryInputFile}...`);
    const buf = fs.readFileSync(binaryInputFile); // Node Buffer
    // IMPORTANT: slice to the exact region, avoid leading offset issues.
    const binaryData = buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength); // ArrayBuffer

    const jsObject = pduToJs(binaryData);

    // --- 2) Verify against JSON ---
    console.log(` -> Verifying against ${jsonInputFile}...`);
    const originalObject = JSON.parse(fs.readFileSync(jsonInputFile, 'utf8'));

    // prefer explicit toDict()/toJSON(), fallback to plain object
    const toDict =
      typeof jsObject?.toDict === 'function'
        ? jsObject.toDict()
        : typeof jsObject?.toJSON === 'function'
          ? JSON.parse(jsObject.toJSON())
          : jsObject;

    // NOTE: stringify比較は数値誤差までは吸収しません（必要ならepsilon比較を実装してください）
    const ok = JSON.stringify(originalObject) === JSON.stringify(toDict);
    if (!ok) {
      const failJsonPath = path.join(path.dirname(binaryInputFile), 'js_test_fail.json');
      const gotText =
        typeof jsObject?.toJSON === 'function'
          ? jsObject.toJSON(2)
          : JSON.stringify(toDict, null, 2);
      fs.writeFileSync(failJsonPath, gotText, 'utf8');
      console.error('Error: Deserialized object does not match original JSON object.');
      console.error(` -> Wrote failing object to ${failJsonPath} for debugging.`);
      process.exit(1);
    }
    console.log(' -> JSON verification successful.');

    // --- 3) Serialization ---
    console.log(` -> Serializing object to ${binaryOutputFile}...`);
    const newBinaryData = jsToPdu(jsObject); // expect ArrayBuffer

    // --- 4) Write binary ---
    const outView = new Uint8Array(newBinaryData);
    fs.writeFileSync(binaryOutputFile, Buffer.from(outView));
    console.log(` -> Wrote serialized binary to ${binaryOutputFile}`);
  } catch (error) {
    console.error(`Error during test for ${packageName}/${messageName}:`, error);
    process.exit(1);
  }
}

runTest();
