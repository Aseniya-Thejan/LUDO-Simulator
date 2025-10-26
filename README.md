# 🎲 Ludo_Traditional

A console-based **Ludo** game written in pure C (C99).  
It simulates the traditional four-player board game directly in your terminal using ASCII art and ANSI colors.

---

## 📘 Overview

**Ludo_Traditional** is a simple recreation of the classic board game *Ludo* implemented entirely using command-line output.  
Players (Yellow, Blue, Red, and Green) compete to move all their pieces from **Base → Home** by rolling a single die.  
All turns, dice rolls, and captures are displayed dynamically in the terminal.

The game logic is fully automated — no manual input required. Dice rolls and moves are randomly generated to simulate gameplay.

---

## 🧩 File Structure

| File | Description |
|------|--------------|
| **`Ludo.h`** | Header file containing macros (color codes), function prototypes, and global arrays for player data. Includes header guards to prevent re-inclusion. |
| **`Game_Logic.c`** | Implements all game logic — dice rolls, player order selection, piece movement, capturing, and board updates. |
| **`Main.c`** | Entry point. Seeds the random number generator and starts the game by calling `play_ludo()`. |

---

## 🕹️ Key Features

- 🎨 **ANSI color output** for each player (Red, Green, Yellow, Blue).  
- 🎲 **Automated dice rolls** using `rand()` seeded with time.  
- 🔁 **Turn-based loop** until all pieces reach Home.  
- 📊 **Array-based design** for efficient game state tracking.  
- ⚙️ **Constant space complexity O(1)** — uses fixed-size arrays only.  

---

## 🧮 Data Structures

The program relies on several static arrays for simplicity and performance:

- `int pos[4][4]` → Stores each piece’s position (`1` = base, `101` = home).  
- `int playersvalues[4]` → Stores dice rolls for determining play order.  
- `char *players[4] = {"Yellow","Blue","Red","Green"}`  
- `char *playerorder[4]` → Holds dynamic turn order.  
- `int countt[4]` → Tracks active pieces on board.  
- `int relpos_open[4] = {1,14,27,40}` → Base offsets for each color.  
- `int addwinner[4]` → Stores winners in order.

---

## ⚙️ Build & Run Instructions

### 🧱 Current structure
Since **`Main.c`** directly includes **`Game_Logic.c`**, you should compile **only `Main.c`**.

#### **PowerShell / CMD**
```bash
gcc Main.c -o ludo.exe
./ludo.exe
```

#### **Linux / macOS**
```bash
gcc Main.c -o ludo
./ludo
```

---

### 💡 Recommended refactor (optional)
For safer compilation and cleaner linking:

1. Remove `#include "Game_Logic.c"` from `Main.c`.  
2. Add `#include "Ludo.h"` instead.  
3. Move global variable definitions into `Game_Logic.c` and declare them as `extern` in `Ludo.h`.  

Then compile both files normally:
```bash
gcc Main.c Game_Logic.c -o ludo
./ludo
```

---

## 🧾 Example Output (abridged)

```
🎲 Welcome to LUDO Traditional 🎲
Yellow rolls the dice... gets 6!
Blue rolls the dice... gets 4!
Red rolls the dice... gets 1!
Green rolls the dice... gets 6!
---------------------------------
Player order: Yellow → Green → Blue → Red
---------------------------------
Yellow moves piece 1 from base to board.
Blue moves piece 2 by 4 steps.
...
🏁 Winner: GREEN 🏁
```

---

## ⚠️ Notes

- ANSI color codes (`\033[31m`, `\033[32m`, etc.) are used for colorful terminal output.  
  On **Windows**, these may not appear correctly in Command Prompt — use **Windows Terminal** or **Git Bash**,  
  or enable *Virtual Terminal Processing* in cmd/PowerShell.

- No user input is required — all game flow is automatic.

- Global variables are defined in the header for simplicity, but a future refactor could separate them to prevent linker duplication when building modularly.

---

## 🚀 Possible Improvements

- Add interactive mode (player input instead of automated play).  
- Implement a real visual Ludo board using ASCII graphics.  
- Track and display score statistics for each session.  
- Add sound or animation effects for dice rolls.

---

## 📜 License

This project is free and open-source.  
You can release it under the **MIT License** — recommended for academic and educational projects.

---

## 🤝 Contribution

Contributions are welcome!  
If you’d like to improve gameplay, fix bugs, or refactor structure:

1. Fork this repository  
2. Create a feature branch  
3. Submit a Pull Request with a clear description  

Bug reports and suggestions can be opened in the **Issues** tab.

---

## 🧾 Quick README Template

If you want a short version:

```markdown
# Ludo_Traditional

A console-based Ludo game written in C.  
Simulates a four-player match with ANSI-colored output.

### Files
- `Ludo.h` – constants, prototypes, and globals  
- `Game_Logic.c` – core logic (dice, turns, captures)  
- `Main.c` – entry point

### Build & Run
```bash
gcc Main.c -o ludo
./ludo
```

### Notes
Use a terminal that supports ANSI colors (Windows Terminal / Git Bash).  
Globals are in header for simplicity — refactor recommended.

### License
MIT License © 2025
```
---

**Author:** Aseniya Thejan  
**Language:** C (C99)  
**Created for:** UCSC assignment — Console-based traditional Ludo simulation
