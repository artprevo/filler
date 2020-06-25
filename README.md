# Filler

Filler is an algorithmic game based on filling a grid of know size. The virtual machine sends to a player a placable random piece of a random size, pretty much like in Tetris. 
First player not able to place a piece or giving a wrong position loose.

The purpose of this project was to create the player part. Making an algorithm capable of analyzing a game state and making moves based on enemy positions.

At each piece received, my player will look at the closest enemy position and try to close their path. The goal is making a large space for us tu put pieces and making it smaller
for the opponent.
Algo based on C, pieces and grid treated in linked-list. 
