# nonogram-solver

More details coming. Copied over C++ sudoku scripts, since I think they can be refactored to solve these puzzles as well.


## Input file

format

```
col_count
row_count
col_crit_vect
row_crit_vect
```

example

```
5
7
{{2,1,1},{2},{2,1},{2},{1,3,1}}
{{2,1},{2},{1},{3},{1,3},{},{1,1,1}}
```

## Output file

`#` is black.

`.` is white.

`?` is unknown (should not appear in output).

```
# # . . #
# # . . .
. . . . #
. . # # #
# . # # #
. . . . .
# . # . #
```