/*  This assignment is given by our lecturer Miss Natalie Rose as group assignmnet of the course
Data structures and Filemanagement 2.
The program is designed to find theshortest path to a destination through a maze.
The authors of this program are named in the readme file attached.

We used C++ programming language to find the shortest path between 
a given source cell to a destination cell. 
*/

#include <bits/stdc++.h> 
using namespace std; 
#define ROW 15 
#define COL 22 
  
//To store matrix cell cordinates 
struct Point 
{ 
    int grid_x; 
    int grid_y; 
}; 
  
// A Data Structure for queue used in BFS 
struct queueNode 
{ 
    Point point;  // The cordinates of a cell 
    int distance;  // cell's distance of from the source 
}; 
  
// check whether given cell (row, col) is a valid cell or not. 
bool isValid(int row, int col) 
{ 
    // return true if row number and column number is in range 
    return (row >= 0) && (row < ROW) && 
           (col >= 0) && (col < COL); 
} 
  
// These arrays are used to get row and column numbers of 4 neighbours of a given cell 
int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
int R1, E2, R3, R5, R6, R7, E4, R8;
  
// function to find the shortest path between a given source cell to a destination cell. 
int BFS(int mat[][COL], Point src, Point destination) 
{ 
    // check source and destination cell of the matrix have value 1 
    if (!mat[src.grid_x][src.grid_y] || !mat[destination.grid_x][destination.grid_y]) 
        return -1; 
  
    bool visited[ROW][COL]; 
    memset(visited, false, sizeof visited); 
      
    // Mark the source cell as visited 
    visited[src.grid_x][src.grid_y] = true; 
  
    // Create a queue for BFS 
    queue<queueNode> q; 
      
    // Distance of source cell is 0 
    queueNode s = {src, 0}; 
    q.push(s);  // Enqueue source cell 
  
    // Do a BFS starting from source cell 
    while (!q.empty()) 
    { 
        queueNode curr = q.front(); 
        Point point = curr.point; 
  
        // If we have reached the destination cell, we are done 
        if (point.grid_x == destination.grid_x && point.grid_y == destination.grid_y) 
            return curr.distance; 
  
        // Otherwise dequeue the front cell in the queue and enqueue its adjacent cells 
        q.pop(); 
  
        for (int i = 0; i < 4; i++) 
        { 
            int row = point.grid_x + rowNum[i]; 
            int col = point.grid_y + colNum[i]; 
              
            // if adjacent cell is valid, has path and 
            // not visited yet, enqueue it. 
            if (isValid(row, col) && mat[row][col] &&  
               !visited[row][col]) 
            { 
                // mark cell as visited and enqueue it 
                visited[row][col] = true; 
                queueNode Adjcell = { {row, col}, 
                                      curr.distance + 1 }; 
                q.push(Adjcell); 
            } 
        } 
    } 
  
    // Return -1 if destination cannot be reached 
    return -1; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int mat[ROW][COL] = 
    { 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, R1, 1, 0, 0, 0, 0, 1, R3 ,1 ,0 ,0 ,0 ,0 ,1 ,R5 ,1 ,0 ,0 ,0 ,0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, R7, 1},
		{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{E2, 0, 0, 0, 0, 0,	1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,	0, 1, 0, 1},
		{1, 1, 1, 1, 1,	0, 1, 0, 1,	0, 0, 1, 0,	1, 0, 0, 0,	0, 0, 1, R6, 1},
		{1, 0, 0, 0, 1,	0, 1, 0, 1,	0, 0, 1, 0,	1, 0, 0, 0,	0, 0, 1, 1,	1},
		{1, 0, 0, 0, 0,	0, 1, 0, 1,	0, 0, 1, 0,	1, 0, 0, 0,	0, 0, 0, 0,	1},
		{1, 1, 1, 1, 1,	1, 1, 0, 1,	0, 0, 1, 0,	1, 0, 0, 0,	0, 0, 0, 0,	1},
		{1, R8,	0, 0, 0, 0,	0, 0, 1, 0,	0, 1, 0, 1,	0, 0, 0, 0,	0, 0, 0, 1},
		{1, 1, 1, 1, 1,	1, 1, 1, 1,	1, 1, 1, E4, 1,	1, 1, 1, 1,	1, 1, 1, 1}
 }; 
  
    Point source = {0, 0}; 
    Point destination = {3, 4}; 
    
    cout << ("Welcome to Group One's Algorithm representing the shortes path through a maze \n\n");
  
    int distance= BFS(mat, source, destination); 
  
    if (distance != INT_MAX) 
        cout << "Shortest Path is " << distance << "\n\n"; 
    else
        cout << "Shortest Path doesn't exist"; 
  
  cout << ("THANK YOU FOR USING OUR PROGRAM! \n\n");
  system ("pause");
    return 0; 
} 


