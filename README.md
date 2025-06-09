# 🧱 Jenga Tower Game (in C)

A gamified terminal-based project that teaches **stack vs heap memory**, **buffer overflows**, and **secure vs insecure coding practices** — using the metaphor of a Jenga tower.


---

## 🎮 What This Is

In this C project, each Jenga block is a dynamically allocated object (`malloc`) pushed onto a simulated tower (stack). You’ll interact with the game through a terminal menu, performing actions like:

- ✅ Pushing blocks (safe or unsafe)
- ❌ Popping blocks
- 💣 Simulating buffer overflows
- 🏗️ Visualizing memory instability
- 📜 Logging actions

---

## 🚀 Getting Started

### ✅ Prerequisites
- GCC or Clang (tested with GCC 11+)
- `make` and `bash`-like shell

### 🛠 Build Instructions

```bash
git clone https://github.com/sukanto-m/jenga-tower-game.git
cd jenga-tower-game
make
./jenga_game
