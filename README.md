# VERDE - aVl trEe foR Don't rEprove

## Summary

- [1. Introduction](#1-introduction)
- [2. Installing](#2-installing)
- [3. Usage](#3-usage)
- [4. Authorship](#4-authorship)

## 1. Introduction

This project named VERDE (aVl trEe foR Don't rEprove) it's a project created to improve my personal grade in Basic Data Structures II at [IMD/UFRN](http://imd.ufrn.br).

The project consists on implementing an AVL tree insertion algorithm, but this software (developed in C++) can search a node into the tree too.

## 2. Installing

This software was developed in C++, using [CMake](http://cmake.org) (please, [install CMake](https://github.com/victorvieirar/CMake-Installation) before use this project).

With CMake ready on your machine, just go to the project root folder and, on terminal, type: `cd build && cmake ..`.
That's will create the `binary` file on `./bin/` folder. Done that, you may use the program however you want to.

## 3. Usage

The program has 3-ways to use:

- The first one is _input_:
  You may use any text files in this format [ `x1 x2 x3 ... xn` ] where `xn` it's an integer number that will be insert into the tree.

To use this mode, you must type `./bin/verde <filepath>`.

> We created a sample file called `default.txt` into `./data` folder that you may use.

- The second one is _cmd_:
  You may create your own tree with commands `insert`, `find`, `print` and may ask by help typing `help` or `exit` the program.

To use this mode, you must type `.bin/verde --c` or `.bin/verde -commands`. (you can use `-c` or `--commands` too...)

- The third one is _both_ mode:
  You may use a text file to create the base tree and may modify that tree after.

To use this mode, you must type `.bin/verde <filepath> --c` or `.bin/verde --c <filepath>`. (all variants of `--c` may be used too).

## 4. Authorship

This project was developed by [Victor Raphaell Vieira Rodrigues](http://github.com/victorvieirar) (me). You may contact me for questions at GitHub or [email me](mailto:victorvieira89@gmail.com).
