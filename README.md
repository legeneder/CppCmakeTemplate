
# Template For C++ Projects 

This is a template for C++ projects. What you get:

-   Sources, headers and test files separated in distinct folders.
-   External libraries that are locally cloned by [Github](https://github.com).
-   External libraries installed and managed by [Conan](https://conan.io/).
-   Use of modern [CMake](https://cmake.org/) for building and compiling.
-   Unit testing, using [GTest](https://github.com/google/googletest), Logging, using [Loguru](https://github.com/emilk/loguru) and Benchmarking, using [Celero](https://github.com/DigitalInBlue/Celero).
-   Continuous testing with [Travis-CI](https://travis-ci.org/) and [Appveyor](https://www.appveyor.com/).
-   Code coverage reports, including automatic upload to [Codecov](https://codecov.io).
-   Code documentation with [Doxygen](http://www.stack.nl/~dimitri/doxygen/).
-   Optional: Use of [VSCode](https://code.visualstudio.com/) with the C/C++ and CMakeTools extension.

## Structure
``` text
├── CMakeLists.txt
├── app
│   └── main.cc
├── benchmarks
│   ├── CMakesLists.txt
│   └── main.cc
├── docs
├── ├── Doxyfile
│   └── html...
├── external
│   ├── CMakesLists.txt
│   ├── linalg...
│   ├── loguru...
│   └── Celero...
├── include
│   └── MyLib
│       └── my_lib.h
├── src
│   ├── CMakesLists.txt
│   └── MyLib
│       ├── CMakesLists.txt
│       └── my_lib.cc
└── tests
    ├── CMakeLists.txt
    └── main.cc
```

Sources go in [src/](src/), header files in [include/](include/), main programs in [app/](app),
tests go in [tests/](tests/) and benchmarks go in [benchmarks/](benchmarks/).

If you add a new executable, say `app/new_executable.cc`, you only need to add the following two lines to [CMakeLists.txt](CMakeLists.txt): 

``` cmake
add_executable(new_executable app/new_executable.cc)   # Name of exec. and location of file.
target_link_libraries(new_executable PRIVATE ${LIBRARY_NAME})  # Link the executable to lib built from src/*.cc (if it uses it).
```

You can find the example source code that builds the `main` executable in [app/main.cc](app/main.cc) under the `Build` section in [CMakeLists.txt](CMakeLists.txt). 
If the executable you made does not use the library in [src/](src), then only the first line is needed.
