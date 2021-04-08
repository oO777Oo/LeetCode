# 944. The cheapest way

### Each cell of the rectangular table N×M contains some number. Initially the player is in the upper left cell. During one move he is allowed to move to the adjacent cell either to the right or to the bottom (it is forbidden to move up and to the left). When passing through a cell from the player take as many kilograms of food, what number is written in this cell (food is taken also for the first and the last cell of his path).

### Requirement is to find the minimum weight in kilograms of food, giving which the player can get to the bottom right corner.

### Input data:
```
Two numbers N and M are entered - the size of the table (1≤N≤20, 1≤M≤20). Then comes N lines of M numbers in each - the size of fines in kilograms for passing through the corresponding cells (numbers from 0 to 100).
```

### Output:
```
Print the minimum weight in kilograms of food that you can give to get into the bottom right corner.
```

### Examples:
```
input:
5 5
1 1 1 1 1
3 100 100 100 100
1 1 1 1 1
2 2 2 2 1
1 1 1 1 1
outprint:
11
```