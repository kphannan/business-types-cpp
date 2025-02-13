# CMake template

Template for a project with an application and two libraries.

Layout:

* app
* libs/lib1
* libs/lib2

## Usage

Create the ```build``` directory and configure the build:

```shell
cmake -S . -B build
```

build the project:

```shell
(cd build; cmake --build . --parallel 16 -v && ctest)
```

Optionally run tests with ```ctest``` with this command:

```shell
cmake -E chdir build ctest
```

Optionally run the application:

```shell
cmake -E chdir build app/GraphX
```

## Project layout

```pre
├── CMakeLists.txt
├── README.md
├── app
│   ├── CMakeLists.txt
│   └── src
│       ├── main
│       │   └── cpp
│       │       ├── include
│       │       └── src
│       │           └── foo.cpp
│       └── test
│           └── cpp
│               ├── include
│               └── src
└── libs
    ├── CMakeLists.txt
    ├── lib1
    │   ├── CMakeLists.txt
    │   └── src
    │       ├── main
    │       │   └── cpp
    │       │       ├── include
    │       │       │   └── bar.hpp
    │       │       └── src
    │       │           └── bar.cpp
    │       └── test
    │           └── cpp
    │               ├── include
    │               └── src
    └── lib2
        ├── CMakeLists.txt
        └── src
            ├── main
            │   └── cpp
            │       ├── include
            │       │   └── baz.hpp
            │       └── src
            │           └── baz.cpp
            └── test
                └── cpp
                    ├── include
                    └── src
```
