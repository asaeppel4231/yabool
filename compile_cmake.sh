#!/bin/sh

rm -rf build
mkdir -p build
cd build
cmake ..
if [ $? -eq 0 ]; then
    cmake --build .
fi
