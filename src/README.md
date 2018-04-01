## 1. Build

We use `cmake` to build this project, and out of source build is recommended:

```sh
rm -rf build && mkdir build
cd build && cmake ..
make
```

## 2. Install

```sh
rm -rf install build
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
make install
```
