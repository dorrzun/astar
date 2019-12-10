# A* (A-Star) Pathfinding Algorithm
### Author: Austin Youngerman
  
This code produces a working implementation of the A Star pathfinding algorithm, which finds the shortest path to a given finish, if there is any. The heuristic is F(x) = g(x) + h(x), where:

F = Total "cost" of a path, the higher the value, the less desirable it is.
g = Total distance from the start to the current position by way of the current path
h = Total distance from the start to finish, calculated by either Taxicab (Manhattan) distance or as the crow flies (Euclidean).

### To compile, type: g++ astar.cpp -o astar

### To run using Manhattan distance, type: ./astar test.txt manhattan

### To run using Euclidean distance, type: ./astar test.txt euclidean

I have provided a few test text files that test various characteristics.

test.txt: A simple path to find.

test2.txt: A longer path to find that requires going up and over, and makes sure that it doesn't get stuck hugging the wall adjacent to finish.

test3.txt: A maze with a finish, but no way to get to it.

test4.txt: A huge maze with multiple changes in direction. Ensures that not all points are explored unless necessary.

test5.txt: A maze with slight bias towards a southern path, ensuring the algorithm pursues the best potential direction first.
