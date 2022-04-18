# template_cpp_project

Template for a C++ project using CMake for building
and is documented using Doxygen.

### Prerequisites

- Define `PROJECT_DIR` in your environment. Example: In your `.bashrc` file add
"`export PROJECT_DIR="FULL-PATH-TO-PROJECT-DIR`" or add it to you '`/etc/environment`'
file to use it also in `Sublime Text` build.

### Project Tree

template_cpp_project\
├── build_debug\
├── build_release\
│   └── build\
├── Cmake\
├── doc\
│   └── build\
├── exe\
│   ├── build\
│   ├── Debug\
│   └── Release\
├── include\
├── lib\
└── src
