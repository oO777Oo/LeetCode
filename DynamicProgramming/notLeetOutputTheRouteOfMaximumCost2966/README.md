# Task #2966. Output the route of maximum cost

### In the upper left corner of a rectangular table of size N×M there is a turtle. Each cell of the table contains a number. The turtle can move to the right or down, and the turtle's route ends at the bottom right corner of the table.

### Calculate the sum of numbers written in the cells through which the turtle crawled (including the starting and ending cells). Find the largest possible value of this sum and the route that reaches this sum.

### Input data
The first line of input contains two natural numbers N and M, not exceeding 100 - the size of the table. Then comes N lines, each line contains M numbers separated by spaces - the description of the table. All numbers in the table cells are integers and can take values from 0 to 100.

### Output data
The first line of the output contains the maximum possible sum, the second line - the route, along which this sum is reached. The route is output as a sequence, which should contain N-1 letter D, indicating movement downwards, and M-1 letter R, indicating movement to the right. If there are several such sequences, exactly one (any) of them must be printed.

### Example 1:
```
intput: 
5 5
9 9 9 9 9
3 0 0 0 0
9 9 9 9 9
6 6 6 6 8
9 9 9 9 9

output:
74
DDRRRRDD
```
