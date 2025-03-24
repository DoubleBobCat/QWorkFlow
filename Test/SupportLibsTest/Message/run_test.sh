#!/bin/sh
mkdir -p build
cd build || exit 1
cmake .. -G "Unix Makefiles" || exit 1
cmake --build . || exit 1
./Test