# 42_so_long

A small 2D game

## Game rules

* The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
* The player moves in these 4 directions: up (keyboarde W), down (keyboarde S), left (keyboarde A), right (keyboarde D).
* If the player touchs an enemy he dies

## Requirements:
* [Minilibx](https://github.com/42sp/minilibx-linux) installed (for 42 students using Workspaces the library is already installed)
* Minilibx requires differents libraries depending on the OS as explained [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* For Linux or Mac OS update Makefile as indicated [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) in the installation and compilation parts.

### Running the game

If you are using Workspaces just
* run ```make bonus```
* run ```./so_long_bonus map.ber``` with the specific map of your choose

Map files are provided in ``assets/maps`` folder but you can create your own maps
The game only accepts a map in the \*ber format and the characters:
* 1 for walls
* 0 for empty space
* C for colletibles
* E for exit
* P for player

When there is more than one player position the subsequent 'P's are set as enemies.

Enjoy and have fun!
