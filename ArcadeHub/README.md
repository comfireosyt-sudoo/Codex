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
1. GNU Make
2. A C++17 toolchain (`g++` or `arm-none-eabi-g++`)
3. NumWorks app tooling (nwlink/nwbuild) if you want real device-compatible binaries

## Build (Make only)
```bash
make clean
make
```
This Makefile now uses `tools/package.py`, which requires official NumWorks tooling (`nwbuild`) to generate a valid `.nwa` package with metadata/icon.

## Output behavior on Windows/MSYS2
- If `nwbuild` is available, `make` produces `output/ArcadeHub.nwa` with proper metadata.
- If `nwbuild` is missing, the build fails intentionally instead of generating an invalid fake `.nwa`.
- Remove stale old files from previous runs with:
```bash
make clean
```


## Why you saw missing icon/name and `Size: NaN KB`
That happens when a desktop executable is renamed to `.nwa`. The NumWorks installer expects a real package format containing metadata and icon resources, not a renamed `.exe`/ELF.

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
