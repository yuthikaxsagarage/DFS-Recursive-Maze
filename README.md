# maze
Simple maze from Depth First Search (DFS) recursive back-tracker
This algorithm is a randomized version of the depth-first search algorithm implemented with a stack, this approach is one of the simplest ways to generate a maze using a computer.

Consider the space for a maze being a large grid of cells (like a large chess board), each cell starting with four walls. Starting from a random cell, the computer then selects a random neighbouring cell that has not yet been visited. The computer removes the wall between the two cells and marks the new cell as visited, and adds it to the stack to facilitate backtracking. 

The computer continues this process, with a cell that has no unvisited neighbours being considered a dead-end. When at a dead-end it backtracks through the path until it reaches a cell with an unvisited neighbour, continuing the path generation by visiting this new, unvisited cell (creating a new junction). This process continues until every cell has been visited, causing the computer to backtrack all the way back to the beginning cell. We can be sure every cell is visited.

<a href="https://imgflip.com/gif/3cqckq"><img src="https://i.imgflip.com/3cqckq.gif" title="made at imgflip.com"/></a>
