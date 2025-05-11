cmake_minimum_required (VERSION 3.30 FATAL_ERROR) # first version with import std; support
# note: latest CMake version 4.0.2 did not work at all! - version 3.31.x seem to work!

# enable import std; support
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
set(CMAKE_CXX_MODULE_STD 1)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("fmtlib-module-experiment")
message("${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES 1)

add_compile_definitions(-D_UTF8) # note: mvsc would complain that option is different!
# note: you can also disable FMT_UNICODE - does not make this work!

add_subdirectory(fmt)

# set(FMT_MODULE ON) - NOTE: set this externally!
target_compile_definitions(fmt
  PRIVATE FMT_IMPORT_STD=1) # hack to enable import std; mode for fmtlib

add_library(fmtwrap)
target_sources(fmtwrap
  PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "FmtWrap.cpp"
)
target_compile_features(fmtwrap
  PUBLIC cxx_std_23
)
target_link_libraries(fmtwrap
  PUBLIC
    fmt::fmt
)

add_library(greeter)
target_link_libraries(greeter
  PUBLIC
    fmtwrap
)
target_sources(greeter
  PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "Greeter.cpp"
)

# Add source to this project's executable.
add_executable(main)
target_sources(main
  PRIVATE
    "main.cpp"
)
target_link_libraries(main
  PUBLIC
    greeter
)
