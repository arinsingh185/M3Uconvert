[README.md](https://github.com/user-attachments/files/29817293/README.md)
# M3Uconvert

A small Windows utility that organizes multi-disc PS1 `.chd` files and automatically generates `.m3u` playlists, so multi-disc games show up as a single entry in frontends like [Cocoon](https://cocoon-shell.com/), [ES-DE](https://es-de.org/), and emulators like [DuckStation](https://www.duckstation.org/).

## Why

Emulator frontends normally show every disc of a multi-disc game (Final Fantasy VII, Resident Evil, etc.) as a separate entry in your library. An `.m3u` playlist file fixes this by listing all the discs together, letting the frontend and emulator treat the whole game as one item and handle disc-swapping automatically.

Writing these by hand for a large ROM collection is tedious. M3Uconvert scans a folder of `.chd` files, groups them by game name, and generates a correctly formatted `.m3u` file for each multi-disc game — all sitting flat in the same folder, which is what most frontends and DuckStation expect.

## Features

- Automatically detects and groups multi-disc `.chd` files by game name
- Sorts discs in correct order (Disc 1, Disc 2, Disc 3...) inside each playlist
- Skips single-disc games (no unnecessary `.m3u` files)
- Generates playlists directly alongside your ROM files — no nested folders, fully compatible with Cocoon, ES-DE, DuckStation, and most other frontends
- Simple GUI — select a folder, click organize, done

## Requirements

- Windows 10/11 (64-bit)
- Currently supports `.chd` ROM files only

## Installation

1. Go to the [Releases](../../releases) page.
2. Download the latest `M3Uconvert-vX.X.X-win64.zip`.
3. Extract it anywhere on your computer.
4. Run `M3Uconvert.exe`.

> **Note:** Windows may show a SmartScreen warning ("Windows protected your PC") since this is an unsigned, small open-source tool. Click **More info** → **Run anyway** to proceed. This is expected — the source code is fully available in this repo for review.

## Usage

1. Launch `M3Uconvert.exe`.
2. Click **Select Folder** and choose the folder containing your `.chd` files.
3. Click **Organize**. The tool will:
   - Scan for `.chd` files
   - Group discs belonging to the same game
   - Generate a `.m3u` playlist for each multi-disc game, placed in the same folder
4. Point your frontend (Cocoon, ES-DE, etc.) at that folder and rescan your library. Each multi-disc game should now appear as a single entry.

## Example

Before:
```
Final Fantasy VII (USA) (Disc 1).chd
Final Fantasy VII (USA) (Disc 2).chd
Final Fantasy VII (USA) (Disc 3).chd
```

After running M3Uconvert:
```
Final Fantasy VII (USA) (Disc 1).chd
Final Fantasy VII (USA) (Disc 2).chd
Final Fantasy VII (USA) (Disc 3).chd
Final Fantasy VII.m3u
```

## Building from source

This project is built with **Qt 6** and **CMake**.

### Prerequisites
- Visual Studio 2022 with C++ desktop development workload
- Qt 6.5+ (with MSVC 2022 64-bit component)
- CMake 3.19+

### Build steps

```powershell
git clone https://github.com/arinsingh185/M3Uconvert.git
cd M3Uconvert
cmake -B out -S . -DCMAKE_BUILD_TYPE=Release
cmake --build out --config Release
```

### Deploying a standalone build

To bundle the required Qt DLLs so the executable can run on machines without Qt installed:

```powershell
cmake --install out --config Release --prefix "$PWD\install"
```

The deployed application will be in `install\bin\`.

## Known limitations

- Only `.chd` files are currently supported (no `.cue`/`.bin`, `.iso`, etc.)
- Disc grouping relies on standard naming conventions (e.g. `Game Name (Disc 1).chd`) — games with unusual naming may not be grouped correctly

## Contributing

Issues and pull requests are welcome. If you run into a game whose discs aren't grouped correctly, please open an issue with the filenames involved.
