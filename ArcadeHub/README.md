# Arcade Hub for NumWorks

Arcade Hub is a multi-game launcher for NumWorks calculators built in C++17 using a NumWorks-style app architecture.

## Included games
- Tetris
- Sudoku
- Water Sort Puzzle
- Memory Match
- Block Blast
- Fruit Merge
- Hangman
- Checkers
- Bonus: Snake, 2048, Minesweeper

## Controls (NumWorks)
- Arrow keys: move cursor/selection
- OK/EXE: confirm
- BACK: back/pause
- HOME: exit app

## Build requirements
1. Windows 10+ (for `build.bat`)
2. GNU Make
3. A C++17 toolchain (`arm-none-eabi-g++` preferred, desktop fallback supported)
4. NumWorks app tooling (nwlink/nwbuild if available)

## Build
```bat
build.bat
```
The script:
1. Detects available compiler/toolchain
2. Builds sources
3. Produces `output/ArcadeHub.nwa` (or desktop fallback binary wrapped with `.nwa` placeholder)
4. Shows clear success/failure logs


## Output behavior on Windows/MSYS2
- The build now keeps intermediate `.exe` files in `build/` only and deletes them after packaging.
- The `output/` folder is intentionally left with only one artifact: `ArcadeHub.nwa`.
- If you still see old `ArcadeHub.exe` or `ArcadeHub.nwa.exe` files, they are stale leftovers; run:
```bash
make clean
make
```

## Install on NumWorks
- If built with the NumWorks SDK tooling, install generated `.nwa` using your normal NumWorks install flow.
- Typical flow is with official tooling / WebUSB installer depending on your environment.

## Architecture
- `core/`: launcher/menu loop, base interfaces
- `games/`: one class per game (logic + rendering + input)
- `storage/`: robust save manager with corruption recovery
- `assets/`: static palettes/text labels
- `src/main.cpp`: entrypoint and app lifecycle

## Persistence
Saved values:
- unlocked levels
- highscores
- global/per-game statistics
- selected difficulty and settings
- completion flags and puzzle states

Save file path at runtime: `storage/arcadehub.sav`.
Corrupt save files are auto-reset safely.

## Packaging layout
```
ArcadeHub/
├── build.bat
├── README.md
├── Makefile
├── assets/
├── core/
├── include/
├── games/
├── storage/
├── build/
└── output/
    └── ArcadeHub.nwa
```


## Common Windows/MSYS2 fix
If you see `ld.exe: cannot open output file output/ArcadeHub.exe: No such file or directory`, run:
```bash
mkdir -p output
make clean
make
```
The Makefile now auto-creates the output folder before linking.
