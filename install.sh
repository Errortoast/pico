#!/bin/bash

echo "Checking for dependencies..."
if [ -x "$(command -v apt-get)" ]; then
    sudo apt-get update && sudo apt-get install -y libncurses5-dev libncursesw5-dev g++
elif [ -x "$(command -v dnf)" ]; then
    sudo dnf install -y ncurses-devel gcc-c++
elif [ -x "$(command -v yum)" ]; then
    sudo yum install -y ncurses-devel gcc-c++
elif [ -x "$(command -v pacman)" ]; then
    sudo pacman -S --noconfirm ncurses gcc
else
    echo "Could not find a supported package manager."
    echo "Please manually install ncurses-devel and g++ to continue."
    exit 1
fi

echo "Compiling..."
g++ -o pico main.cpp -lncurses

if [ $? -eq 0 ]; then
    echo "Installing to /usr/local/bin..."
    sudo mv pico /usr/local/bin/
    echo "------------------------------------------------"
    echo "Success! Type 'pico <filename>' to start."
else
    echo "Compilation failed. Check if main.cpp exists in this folder."
    exit 1
fi
