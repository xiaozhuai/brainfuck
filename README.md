# Brainfuck

[English](README.md) [中文](README_CN.md)

Multi-language implementation of Brainfuck interpreter.

No limit at all! Do what fuck you want!

# Implementation

1. c
2. cpp
3. node
4. php

# Brainfuck Scripts

1. hello-world-1
2. hello-world-2
3. add
4. multiply
5. toupper

# Contribution

Pull requests are welcome : )

# About Brainfuck

Below contents are from wikipedia. Check [https://en.wikipedia.org/wiki/Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) to learn more!

Brainfuck is an esoteric programming language created in 1993 by Urban Müller.

Notable for its extreme minimalism, the language consists of only eight simple commands and an instruction pointer. While it is fully Turing complete, it is not intended for practical use, but to challenge and amuse programmers. Brainfuck simply requires one to break commands into microscopic steps.

## Language design

The language consists of eight commands, listed below. A brainfuck program is a sequence of these commands, possibly interspersed with other characters (which are ignored). The commands are executed sequentially, with some exceptions: an instruction pointer begins at the first command, and each command it points to is executed, after which it normally moves forward to the next command. The program terminates when the instruction pointer moves past the last command.

The brainfuck language uses a simple machine model consisting of the program and instruction pointer, as well as a one-dimensional array of at least 30,000 byte cells initialized to zero; a movable data pointer (initialized to point to the leftmost byte of the array); and two streams of bytes for input and output (most often connected to a keyboard and a monitor respectively, and using the ASCII character encoding).

## Commands

The eight language commands each consist of a single character:

| Character | Meaning                                                                                                                                                                           |
| --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| >         | increment the data pointer (to point to the next cell to the right).                                                                                                              |
| <         | decrement the data pointer (to point to the next cell to the left).                                                                                                               |
| +         | increment (increase by one) the byte at the data pointer.                                                                                                                         |
| -         | decrement (decrease by one) the byte at the data pointer.                                                                                                                         |
| .         | output the byte at the data pointer.                                                                                                                                              |
| ,         | accept one byte of input, storing its value in the byte at the data pointer.                                                                                                      |
| [         | if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command. |
| ]         | if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command. |


Brainfuck programs can be translated into C using the following substitutions, assuming ptr is of type char* and has been initialized to point to an array of zeroed bytes:

| Brainfuck command | C equivalent           |
| ----------------- | ---------------------- |
| (Program Start)   | char ptr[30000] = {0}; |
| >                 | ++ptr;                 |
| <                 | --ptr;                 |
| +                 | ++*ptr;                |
| -                 | --*ptr;                |
| .                 | putchar(*ptr);         |
| ,                 | *ptr=getchar();        |
| [                 | while (*ptr) {         |
| ]                 | }                      |

As the name suggests, Brainfuck programs tend to be difficult to comprehend. This is partly because any mildly complex task requires a long sequence of commands and partly because the program's text gives no direct indications of the program's state. These, as well as Brainfuck's inefficiency and its limited input/output capabilities, are some of the reasons it is not used for serious programming. Nonetheless, like any Turing complete language, Brainfuck is theoretically capable of computing any computable function or simulating any other computational model, if given access to an unlimited amount of memory. Although Brainfuck programs, especially complicated ones, are difficult to write, it is quite trivial to write an interpreter for Brainfuck in a more typical language such as C due to its simplicity. 
