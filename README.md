# Test using fmtlib as C++20 module

## Steps to build

### Use correct CMake Versions

You need CMake 3.30+ for the `import std;` support.

Note: CMake version 4.0.2 did not work for me! - 3.31.x versions seem to work fine.

### Clone this repository

```bash
git clone --recurse-submodules https://github.com/arBmind/fmtlib-module-experiment.git
```

### Patch the fmt library

In `fmt/include/fmt/format-inl.h` the include of locale is wrong - Simply comment out line 26.
```cpp
// #if FMT_USE_LOCALE
// #  include <locale>
// #endif
```

### Setup CMakeCache.txt

Set `FMT_MOULE` to `ON` to enable module support.

## Test with MSVC 2022 version 17.3.6

Compiler keeps crashing as soon at fmt::format is used.

```
  ... Building CXX object CMakeFiles\greeter.dir\Greeter.cpp.obj
  FAILED: CMakeFiles/greeter.dir/Greeter.cpp.obj CMakeFiles/greeter.dir/greeter.ifc 
  ...\VC\Tools\MSVC\1443~1.348\bin\Hostx64\x64\cl.exe  /nologo /TP -DFMT_UNICODE=0 -D_UTF8 -I...\fmt\include /DWIN32 /D_WINDOWS /EHsc /Ob0 /Od /RTC1 -std:c++latest -MDd -ZI /reference fmt=fmt\CMakeFiles\fmt.dir\fmt.ifc /showIncludes @CMakeFiles\greeter.dir\Greeter.cpp.obj.modmap /FoCMakeFiles\greeter.dir\Greeter.cpp.obj /FdCMakeFiles\greeter.dir\greeter.pdb /FS -c ...\Cpp20ModuleCMake\Greeter.cpp
```