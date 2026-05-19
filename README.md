# 🎮 XanderCross

XanderCross is a terminal-based mini game hub built with **C++** using core **Object-Oriented Programming (OOP)** concepts.

The project focuses on clean architecture, runtime polymorphism, input validation, and interactive terminal gameplay.

---

# ✨ Features

- Terminal-based game hub
- Colorful ANSI terminal UI
- Runtime polymorphism
- Abstract base class architecture
- Input validation system
- Dynamic scoreboards
- Replay functionality
- Modular OOP design

---

# 🎮 Included Games

## 🔢 Number Guess Game
- Player vs Computer
- Player vs Friend
- Multiple difficulty levels
- Attempt limitation system
- Score tracking

## ✂️ Rock Paper Scissor
- Randomized computer moves
- Win / Loss / Tie tracking
- Replay system

---

# 🧠 OOP Concepts Used

| Concept | Implementation |
|---|---|
| Encapsulation | Private data members |
| Inheritance | Game classes inherit from `GameHub` |
| Abstraction | Pure virtual `play()` function |
| Polymorphism | Base class pointer calling derived games |

---

# 🏗️ Project Structure

```text
XanderCross/
│
├── main.cpp
├── README.md
└── .gitignore
```

---

# ⚙️ Technologies Used

- C++
- STL
- OOP
- `<thread>`
- `<chrono>`
- ANSI Escape Codes
- Git & GitHub

---

# 🚀 Compile & Run

## Compile

### Windows
```bash
g++ main.cpp -o gamehub
```

### Linux / macOS
```bash
g++ main.cpp -o gamehub -pthread
```

---

## Run

### Windows
```bash
gamehub
```

### Linux / macOS
```bash
./gamehub
```

---

# 📌 Controls

## Number Guess Game

| Input | Action |
|---|---|
| Number | Guess number |
| `q` | Return to main menu |

---

## Rock Paper Scissor

| Input | Action |
|---|---|
| `r` | Rock |
| `p` | Paper |
| `s` | Scissor |

---

# 📈 Future Improvements

- Tic Tac Toe
- Snake Game
- File handling
- Leaderboard system
- Improved AI
- Modular header/source structure

---

# 👨‍💻 Developer

**Mehedi Hasan Sifat**  
GitHub: **SifatNycto**