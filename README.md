# Sudoku
Repository for a quick game I spliced together and built upon in C that generates a partially complete sudoku puzzle and then solves it.

Generator program modified from here: https://www.geeksforgeeks.org/program-sudoku-generator/

Solver algorithm modified from here: https://www.geeksforgeeks.org/sudoku-backtracking-7/

Example output:
```
Generated Sudoku Puzzle:
6 9 0 ┃ 1 2 3 ┃ 0 5 7 
5 2 0 ┃ 0 7 8 ┃ 0 9 0 
1 3 7 ┃ 9 0 5 ┃ 0 6 8 
━━━━━━╋━━━━━━━╋━━━━━━
2 4 0 ┃ 0 6 9 ┃ 1 7 5 
8 5 0 ┃ 0 1 7 ┃ 9 3 2 
0 1 9 ┃ 0 3 2 ┃ 6 8 4 
━━━━━━╋━━━━━━━╋━━━━━━
0 7 1 ┃ 0 5 6 ┃ 8 4 3 
4 0 5 ┃ 3 9 1 ┃ 7 2 0 
3 0 2 ┃ 7 8 4 ┃ 5 1 0 

Solved Sudoku Puzzle:
6 9 8 ┃ 1 2 3 ┃ 4 5 7 
5 2 4 ┃ 6 7 8 ┃ 3 9 1
1 3 7 ┃ 9 4 5 ┃ 2 6 8
━━━━━━╋━━━━━━━╋━━━━━━
2 4 3 ┃ 8 6 9 ┃ 1 7 5
8 5 6 ┃ 4 1 7 ┃ 9 3 2
7 1 9 ┃ 5 3 2 ┃ 6 8 4
━━━━━━╋━━━━━━━╋━━━━━━
9 7 1 ┃ 2 5 6 ┃ 8 4 3
4 8 5 ┃ 3 9 1 ┃ 7 2 6
3 6 2 ┃ 7 8 4 ┃ 5 1 9
```
