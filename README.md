# mpgre
MultiPlatform Graphics Rendering Engine

## Vulkan SDK
Current version of the Vulkan SDK is 1.3.261.0. The SDK must be installed as recommended/default. 
Ensure that the environment variables (VULKAN_SDK VK_SDK_PATH) exists and is up-to-date.

## Dependencies
| Package                 | Notes |
| -------                 | ----- |
| git                     | Must be preinstalled |
| vcpkg                   | Must be preinstalled, see https://vcpkg.io/en/getting-started |


## Building
Ensure that the path to **vcpkg** is changed to suit your setup. 
```cmake -B build -S .. -DCMAKE_TOOLCHAIN_FILE=C:\tools\vcpkg\scripts\buildsystems\vcpkg.cmake```
