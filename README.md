# brainfuck

36 lines Brainfuck interpreter written in C++.

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
