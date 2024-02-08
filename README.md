# So_long

## Score
![project score](/assets/score.png)

## Description:
So Long is a small 2D game project developed in C language. The objective of this project is to create a basic computer graphics project focusing on window management, event handling, colors, textures, and basic gameplay elements. The game utilizes the MiniLibX graphical library for window creation, image rendering, and user input handling.

## Features:
- Player controls a character in a 2D environment.
- Collect all collectibles present on the map and escape by choosing the shortest route.
- Movement controls using the WASD keys.
- Display of current number of movements.
- Error handling for map validation and misconfigurations.

## Map:
- The map must be constructed with 3 components: walls, collectibles, and free space.
- Map format consists of characters: `0` for an empty space, `1` for a wall, `C` for a collectible, `E` for a map exit, `P` for the player’s starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- Valid paths must be ensured within the map.
- Map files should have the .ber extension and stored in the maps/ directory.

### Example
```bash
11111111111111111
1E0000000000000C1
10100101001000001
10100100101010101
1P0000000C00C0001
11111111111111111
```

## Graphic :
- The program displays the game environment in a window.
- Smooth window management is ensured, including switching to another window, minimizing, etc.
- Pressing ESC or clicking on the window's close button quits the program cleanly.
- The game utilizes images provided by the MiniLibX library for graphical elements.
- Additional graphic features, such as sprite animation, can be implemented for bonus points.

![Game screenshot](/assets/game.png)

## Usage:

Compile the project using the provided Makefile: `make` and run the executable with a map description file as a parameter.
 ```bash
./so_long maps/your_map.ber
```