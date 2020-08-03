# CRC
Cyclic redundancy check algorithm.

## Building

The following commands build the project.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Development

The following command builds the project and
runs the tests.

```bash
cmake ..
cmake --build . --config Degub/Release
ctest -C Debug/Release
```

## Usage

```cpp
#include <crc.hpp>
#include <iostream>
#include <string>
#include <vector>

int main() {
  const std::string Text("Some string 1234567890");
  CRC32::DEFAULT crc32;
  auto result_crc32 = crc32(Text.begin(), Text.end());
  
  const std::vector<std::uint8_t> ByteArray({ 0x10, 0x38, 0x24, 0x13, 0x75, 0x63, 0x1, 0x0, 0x58 });
  CRC16::MODBUS crc16;
  auto result_crc16 = crc16(ByteArray.data(), ByteArray.size());

  return 0;
}
```