#!/bin/bash

clang++ -o "$1" "$1.cpp" && chmod +x "$1" && ./"$1"