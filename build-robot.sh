#!/usr/bin/env bash

set -xe

mkdir -p build
g++ -O2 src/robot/*.cpp -o build/robot
build/robot
