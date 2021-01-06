# brainfuck

36 lines Brainfuck interpreter written in C++.

[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/xiaozhuai/brainfuck)

# Build

## g++

```bash
g++ brainfuck.cpp -o brainfuck
./brainfuck scripts/hello-world-1.bf
```

## cmake

```bash
mkdir build
cd build
cmake ..
make
./brainfuck ../scripts/hello-world-1.bf
```
