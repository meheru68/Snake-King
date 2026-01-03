# snakeKing

A classic Snake game built in C++ for Windows console, featuring smooth gameplay, score tracking, and dynamic tail growth.


## 🎮 About

Snake King is a retro-style snake game that runs directly in your Windows command prompt. Control the snake to eat fruits, grow longer, and achieve the highest score possible while avoiding collisions with yourself.

## 🛠 Technologies Used

- **C++17** - Core programming language
- **Windows.h** - For console manipulation and Sleep()
- **conio.h** - For non-blocking keyboard input (_kbhit() & getch())
- **iostream** - Standard input/output operations

*Platform: Windows (Console Application)*

## ✨ Features

- 🐍 **Smooth Snake Movement** - 100ms refresh rate for responsive controls
- 🍎 **Dynamic Fruit Spawning** - Randomly placed fruits on the game board
- 📏 **Growing Tail** - Snake extends by one segment per fruit eaten
- 🎯 **Score Tracking** - 10 points per fruit collected
- 🔄 **Wrap-around Walls** - Snake reappears on opposite side when hitting walls
- 💀 **Self-Collision Detection** - Game over when snake bites itself
- ⌨️ **Non-blocking Input** - Change direction without pausing the game

## ⌨️ Keyboard Actions

| Key | Action |
|-----|--------|
| `W` | Move **UP** |
| `S` | Move **DOWN** |
| `A` | Move **LEFT** |
| `D` | Move **RIGHT** |
| `S` | **Start** the game (from menu) |

*Note: Controls are case-sensitive (lowercase letters)*

## 🚀 How to Run

### Prerequisites

- Windows OS (7/10/11)
- C++ compiler (MinGW, MSVC, or any IDE like Code::Blocks, Visual Studio)
- Basic knowledge of command line

### Compilation Steps

1. **Clone or download** the repository
   ```bash
   git clone <(https://github.com/meheru68/Snake-King)>
   cd snake-king
   ```

2. **Compile the source code**
   
   Using g++ (MinGW):
   ```bash
   g++ -o snake_game main.cpp
   ```

   Or compile with your preferred IDE.

3. **Run the executable**
   ```bash
   snake_game.exe
   ```

4. **Start playing** - Press `s` when prompted

## 🎮 Gameplay

1. Launch the game and press `s` to start
2. Use WASD keys to control the snake direction
3. Eat fruits (`*`) to grow and earn points
4. Avoid running into your own tail
5. The snake wraps around screen edges
6. Game ends if you collide with yourself
7. Current score displays below the game board

## 💡 Development Process

### 1. **Initial Setup**
- Configured game constants (width, height)
- Initialized snake head position at center
- Placed first fruit randomly

### 2. **Game Loop Architecture**
Created three core functions that run continuously:
- `draw()` - Renders game board each frame
- `input()` - Handles non-blocking keyboard input
- `logic()` - Updates game state and collisions

### 3. **Snake Movement Logic**
- Implemented tail following mechanism using coordinate arrays
- Each tail segment takes the position of the previous one
- Head moves based on current direction

### 4. **Collision System**
- **Wall collision**: Wrap-around mechanic using modulo logic
- **Self collision**: Iterate through tail segments to detect head intersection
- **Fruit collision**: Score increase and tail growth

### 5. **Rendering**
- Built border system with `||` characters
- Used `system("cls")` for screen clearing (simple but effective)
- Implemented layered drawing (borders → snake → fruit → spaces)

## 📚 What I Learned

- **Console Manipulation**: Using Windows-specific libraries for real-time input and screen control
- **Game Loop Structure**: Understanding the draw/input/update cycle fundamental to game development
- **Array Management**: Tracking multiple tail segments using parallel arrays and coordinate history
- **Collision Detection**: Implementing boundary and self-collision checks
- **State Management**: Handling game states (playing, game over) with boolean flags
- **Non-blocking I/O**: Using `_kbhit()` to prevent input from pausing gameplay
- **Performance**: Balancing `Sleep()` timing for smooth but playable speed

## 🔧 Potential Improvements

### Code Quality
- [ ] Replace `system("cls")` with more efficient buffer swapping
- [ ] Use `std::vector` instead of fixed-size arrays for dynamic tail
- [ ] Implement proper random seeding (`srand(time(0))`)
- [ ] Add error handling for edge cases

### Game Features
- [ ] Add difficulty levels (increasing speed)
- [ ] Implement a high score system with file saving
- [ ] Add pause functionality (P key)
- [ ] Create a proper game over screen with restart option
- [ ] Add sound effects using `<windows.h>` Beep()
- [ ] Implement a menu system (Start, Instructions, Quit)

### Visual Enhancements
- [ ] Use Unicode characters (🐍, 🍎) for better graphics
- [ ] Add color support using `SetConsoleTextAttribute()`
- [ ] Create a proper scoreboard layout
- [ ] Add a mini-map or border art

### Cross-Platform Support
- [ ] Replace Windows-specific libraries with cross-platform alternatives (e.g., NCurses)
- [ ] Implement CMake build system

## 🤝 Contributing

This is a learning project, but suggestions and improvements are welcome! Feel free to fork and submit pull requests.

**Happy Gaming!** 🎉

*Built with C++ and lots of debugging sessions.*
