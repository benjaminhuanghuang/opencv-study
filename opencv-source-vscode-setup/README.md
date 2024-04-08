# Setup OpenCV + VSCode on Windows

1. download opencv source code
<https://github.com/opencv/opencv>
<https://github.com/opencv/opencv_contrib>

mkdir C:\opencv

copy the source code to C:\opencv\source

2. Open CMake GUI
Set the source code and build path
    Where is the source code: C:/opencv/source/opencv
    Where to build the binaries: C:/opencv/build

Click "Configure"
    Select "MinGW Makefiles" and "Specify native compilers"
    Compiler C: C:/msys64/ucrt64/bin/gcc.exe
    Compiler C++: C:/msys64/ucrt64/bin/g++.exe

Search "Path"
    Set "OpenCV_EXTRA_MODULES_PATH" to "C:/opencv/source/opencv_contrib/modules"
Search "World"
    Check "BUILD_opencv_world"

Click "Generate"

1. Install

```sh
    cd C:/opencv/build
    minGW32-make install
```

Install to C:/opencv/build/install/

4. Set the environment variable
Add "C:\opencv\build\install\x64\mingw\bin" and "C:\opencv\build\install\x64\mingw\bin" to the PATH

Add environment variable "OPENCV_DIR" with value "C:\opencv\build"
It is required for CMake to find OpenCV package

5. Setup VSCode

Modify c_cpp_peroperties.json
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",

                "C:/opencv/build/install/include",
                "C:/opencv/build/install/include/opencv2"
                "C:/opencv/build/install/include/x64/mingw/lib"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:/msys64/ucrt64/bin/gcc.exe",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64",
        }
    ],
    "version": 4
}
```

Modify task.json
```
"tasks": [
{

    "type": "shell",// process Evse RUE X EM RISE XMITE MIR AS/dicommand: shelL WI*FIST HshelL/
    "label": "multi-thread build",
    "command": "E:\\MinGW\\mingw64\\bin\\g++.exe",
    "args": [
        *-g",
        "${file}"
        "-o",
        "$(fileDirname) \\${fileBasenameNoExtension}-exe",
        // орерси
        "-I", "C: \\opencv\\build\ \install\\include",
        "-I", "C:\\opencv\\build\\install\\include\ \opencv2",
        "-L", "C:\\opencv\\build\\install\\x64\\mingw\\lib",
        "-l", "libopenev_wor1d453",
        "-Wall", 
        "-static-libgce", 
        "-std=c++17"
    ],
    "options": {
        "cwd": "E:\MinGW|\mingw64\\bin
    },
    "presentation": {
        "echo": true,
        "reveal": "always"
        "focus": false,
        "panel": "shared"
    }
}]

```
