
# Filler game

## Video example (this filler is red)

[Watch the video](https://www.youtube.com/watch?v=xW_xOYYXpj0)

## Running this project

1)Build this project 

```
$ make
```

2)Install the [VM](https://github.com/pinelli/module-cunix/tree/master/ex14), program that battles fillers

3)Run the binary with VM


You can checkout this project on Linux x64: 
```
$ cd bin
$ ./start_game -p ./kolesnyk -p ./alg1 -m 100x100.map 

``````

## Task

Player should read his symbol,current map and element from stdin in the following format

```
<symbol>
<map_height> <map_width>
<map_matrix>
<elem_height> <elem_width>
<elem_matrix>
```

## example

```
@
5 5
.....
.....
.....
.....
.....
4 4
*...
*...
*...
*...
```



-----

## Rules

Filler must put element on the map and print position (top left corner of element) according to the following rules:

1. Element must not overflow  other elements on the map
2. Element has to be put next to another element of this player
3. Element doesn't have to go out of range of the map

Filler has only 1 second of running time. If it takes longer, it gets eliminated.
If filler returns position that doesn't match the rules, player gets eliminated

The game is over when all of the players are eliminatedi.

Player who has the most symbols on the map wins.

-----

## Examples

```
map              elem          pos
. . . . .       . . . .        0 1       WRONG
. 1 . . .       . . . .
. 1 1 . .       . . . .
. 1 . . .       * * * *
. . . . .
```

```
map              elem          pos
. . . . .       . . . .        2 2       WRONG
. 1 . . .       . . . .
. 1 1 . .       . . . .
. 1 . . .       * * * *
. . . . .
```

```
map              elem          pos
. . . . .       . . . *        1 1       WRONG
. 1 . . .       . . . *
. 1 1 . .       . . . *
. 1 . . .       . . . *
. . . . .
```
```
map              elem          pos
. . . . .       . . . .        1 1       RIGHT
. 1 . . .       . . . .
. 1 1 . .       . . . .
. 1 . . .       * * * *
. . . . .
```


