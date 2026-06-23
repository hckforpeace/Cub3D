# cub3D

A first-person raycasting engine written in C, inspired by the classic Wolfenstein 3D. cub3D reads a simple text-based map description (`.cub` file) and renders a textured 3D maze you can walk through in real time, using the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library.

This project is part of the [42 school](https://42.fr) curriculum, and is an exercise in computer graphics, mathematics (trigonometry, vectors), and rigorous memory management in C.

> [!NOTE]
> This repository is a work in progress. The sections below describe the intended scope and the target architecture of the engine.

## Features

- **Raycasting renderer** — casts a ray per screen column to draw walls with correct perspective and distance-based scaling, the same technique that powered early FPS games.
- **Textured walls** — north, south, east, and west faces each use their own texture.
- **Solid floor and ceiling** — rendered from configurable RGB colors.
- **Smooth movement** — move with `W` `A` `S` `D` and turn the camera with the arrow keys.
- **Map description files** — levels are defined in human-readable `.cub` files.
- **Robust parsing** — invalid maps, missing textures, or malformed configuration are rejected with a clear error before rendering starts.
- **Clean exit** — quit any time with `ESC` or by closing the window, with no leaks.

## How it works

cub3D uses a technique called **raycasting**. The world is a 2D grid, but the renderer projects it into a pseudo-3D view:

1. For every vertical column of the screen, a ray is cast from the player's position into the map.
2. The ray advances until it hits a wall (DDA traversal of the grid).
3. The distance to that wall determines how tall the column is drawn — closer walls are taller.
4. The wall face that was hit selects which texture to sample and the exact pixel column to draw.

Floor and ceiling are filled with their configured colors, and the process repeats every frame to produce smooth first-person movement.

## Getting started

### Prerequisites

You will need a Linux environment with the following installed:

- `gcc` or `clang` and `make`
- The X11 development headers and helpers MiniLibX depends on: `xorg`, `libxext-dev`, `libbsd-dev`, `zlib1g-dev`

On Debian/Ubuntu:

```sh
sudo apt install build-essential xorg libxext-dev libbsd-dev zlib1g-dev
```

### Build

```sh
git clone <repository-url> cub3D
cd cub3D
make
```

This compiles the bundled MiniLibX and produces the `cub3D` executable.

### Run

```sh
./cub3D maps/example.cub
```

The program takes exactly one argument: the path to a `.cub` map file.

## Map file format

A `.cub` file has two parts: a configuration block (textures and colors) followed by the map layout.

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111
```

| Identifier | Meaning |
| ---------- | ------------------------------------------------- |
| `NO`       | Path to the north wall texture (`.xpm`)           |
| `SO`       | Path to the south wall texture                    |
| `WE`       | Path to the west wall texture                     |
| `EA`       | Path to the east wall texture                     |
| `F`        | Floor color, as `R,G,B` (0–255)                   |
| `C`        | Ceiling color, as `R,G,B` (0–255)                 |

The map itself uses these characters:

| Char         | Meaning                                            |
| ------------ | -------------------------------------------------- |
| `1`          | Wall                                               |
| `0`          | Empty walkable space                               |
| `N` `S` `E` `W` | Player start position and facing direction      |
| ` ` (space)  | Void / outside the map                             |

> [!IMPORTANT]
> The map must be fully enclosed by walls, and it must contain exactly one player start position. Otherwise the program exits with an error.

## Controls

| Key            | Action               |
| -------------- | -------------------- |
| `W` / `S`      | Move forward / back  |
| `A` / `D`      | Strafe left / right  |
| `←` / `→`      | Turn camera          |
| `ESC`          | Quit                 |

## Project structure

```
cub3D/
├── Makefile          # Build rules for the engine and bundled MiniLibX
├── include/
│   └── cub3d.h       # Shared types and prototypes
├── src/
│   └── main.c        # Program entry point
└── mlx_linux/        # Bundled MiniLibX graphics library (X11)
```

## Acknowledgements

- [MiniLibX](https://github.com/42Paris/minilibx-linux) — the lightweight graphics library used for windowing and rendering.
- The raycasting approach is famously documented in [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html).
