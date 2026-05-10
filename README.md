# Pico is a simple terminal-based text editor made in C++

Pico is a lightweight, terminal-based text editor built in C++ using the `ncurses` library. This project was created as a hands-on way to learn C++ fundamentals, file I/O, and terminal UI handling.

## Features

* **Basic Editing:** Type, backspace, and navigate like a standard editor.
* **Scrolling:** Supports vertical and horizontal scrolling for larger files.
* **File I/O:** Open existing files or create new ones via command line arguments.
* **Save Support:** Save your progress with `Ctrl+O`.

## Prerequisites

To compile and run this editor, you need the `ncurses` development library installed on your system:

* **Debian/Ubuntu:** `sudo apt install libncurses5-dev libncursesw5-dev`
* **Fedora:** `sudo dnf install ncurses-devel`
* **macOS:** `brew install ncurses`

## Installation & Compilation

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/errortoast/pico.git](https://github.com/errortoast/pico.git)
    cd pico
    ```

2.  **Compile the source:**
    ```bash
    g++ -o editor main.cpp -lncurses
    ```

## Usage

Run the editor by passing a filename as an argument:

```bash
./pico file.txt
