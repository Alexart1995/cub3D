# cub3D
This project is inspired by the world-famous eponymous "Wolfenstein 3D" (1992) video game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

<img src="https://github.com/Alexart1995/cub3D/blob/main/cub3D.png" width="920" height="480">

## Setup and usage

```
git clone https://github.com/Alexart1995/cub3D.git
make
./cub3D map.cub
```

## Control 

`W` move forward <br>
`S` move back <br>
`A` move left <br>
`D` move right <br>
`←` - rotate left <br>
`→` - rotate right <br>
mouse rotation <br>

## Configuration file map.cub

```
Config file called `map.cub`

R 					resolution
C					ceiling rgb color
F					floor rgb color
NO SO WE EA				paths to textures
S					path to sprite
					empty lines

valid map is surrounded by walls (1) and can contain these characters
1					wall
0					player can move here
2					sprite/item
N S E W					player position and view direction
space					empty space (player can't see them)

map can't be splitted by empty lines
```
## Implemented bonuses
- [x] Wall collisions.
- [x] A minimap system.
- [x] Doors which can open and close.
- [x] Rotate the point of view with the mouse.
- [ ] animated sprite.
