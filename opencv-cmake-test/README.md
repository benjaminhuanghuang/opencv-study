# Setup OpenCV + MinGW + CMake on Windows

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

3. Install

```sh
    cd C:/opencv/build
    minGW32-make install
```

Install to C:/opencv/build/install/

4. Set the environment variable
Add "C:\opencv\build\install\x64\mingw\bin" and "C:\opencv\build\install\x64\mingw\bin" to the PATH

Add environment variable "OPENCV_DIR" with value "C:\opencv\build"
It is required for CMake to find OpenCV package


5. Build OpenCV with CMake and MinGW
```sh
    cmake -B build -G "MinGW Makefiles"
    cmake --build build
```
