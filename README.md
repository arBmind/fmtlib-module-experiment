# Test using fmtlib as C++20 module

## Steps to build

### Use correct CMake Versions

You need CMake 3.30+ for the `import std;` support.

Note: CMake version 4.0.2 did not work for me! - 3.31.x versions seem to work fine.

### Clone this repository

```bash
git clone --recurse-submodules https://github.com/arBmind/fmtlib-module-experiment.git
```

## Compile with MSVC 2022 version 17.14+

Should all work as expected!

Good luck!