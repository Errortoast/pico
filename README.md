# Pico: A Simple C++ Terminal Editor

Pico is a lightweight, terminal-based text editor built in C++ using the `ncurses` library. This project was created as a hands-on way to learn C++ fundamentals, file I/O, and terminal UI handling.

## Quick Install (Linux)

The easiest way to install Pico is to use the universal install script. This script automatically detects your package manager (apt, dnf, pacman, or yum), installs the necessary `ncurses` dependencies, compiles the code, and moves the binary to your system path.

```bash
git clone [https://github.com/errortoast/pico.git](https://github.com/errortoast/pico.git)
cd pico
chmod +x install.sh
./install.sh
```

Once installed, you can launch the editor from any directory by simply typing:
```bash
pico <filename>
```

---

## Features

* **Standard Editing:** Intuitive typing, backspacing, and line manipulation.
* **Smart Scrolling:** Supports both vertical and horizontal scrolling for handling larger files.
* **File I/O:** Open existing files or create new ones via command-line arguments.
* **C++ Powered:** Optimized for speed and minimal resource usage.

## Keybindings

| Key | Action |
| :--- | :--- |
| **Arrow Keys** | Move the cursor |
| **Enter** | Insert a new line |
| **Backspace** | Delete characters or merge lines |
| **Tab** | Insert 4 spaces |
| **Ctrl + O** | **Save** changes to the file |
| **Ctrl + C** | Exit (be sure to save first!) |

---

## Manual Build (Advanced)

If you prefer to compile manually, ensure you have the `ncurses` development headers installed on your system:

* **Debian/Ubuntu:** `sudo apt install libncurses5-dev libncursesw5-dev`
* **Fedora/RHEL:** `sudo dnf install ncurses-devel`
* **Arch Linux:** `sudo pacman -S ncurses`

Then compile using:
```bash
g++ -o pico main.cpp -lncurses
./pico filename.txt
```

## License
This project is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
