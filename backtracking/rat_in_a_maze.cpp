/******************************************************************************

Rat in a Maze:

Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:
Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


bool issafe(int newx,int newy, int n, vector<vector<int>> &visited_array, vector<vector<int>> &maze){
    if(newx<0 ||newy<0 || newx>n-1 || newy>n-1){
        return false;
    }
    
    if(visited_array[newx][newy]==1){
        return false;
    }
    
    if(maze[newx][newy]!=1){
        return false;
    }
    
    return true;
    
}
void solve_maze(int newx, int newy, vector<vector<int>> &maze,
vector<vector<int>> &visited_array, int n, string path, vector<string> &output_path){
    
    if(newx==n-1 && newy==n-1){
        output_path.push_back(path);
        return;
    }
    
    // DLRU (Sorted Order)
    // Down 
    if(issafe(newx+1, newy, n, visited_array, maze)){
        visited_array[newx+1][newy]=1;
        solve_maze(newx+1, newy, maze, visited_array, n, path+"D", output_path);
        visited_array[newx+1][newy]=0;
    }
    
    // Left
    if(issafe(newx, newy-1, n, visited_array, maze)){
        visited_array[newx][newy-1]=1;
        solve_maze(newx, newy-1, maze, visited_array, n, path+"L", output_path);
        visited_array[newx][newy-1]=0;
    }
    
    // right
    if(issafe(newx, newy+1, n, visited_array, maze)){
        visited_array[newx][newy+1]=1;
        solve_maze(newx, newy+1, maze, visited_array, n, path+"R", output_path);
        visited_array[newx][newy+1]=0;
    }
    
    // Up
    if(issafe(newx-1, newy, n, visited_array, maze)){
        visited_array[newx-1][newy]=1;
        solve_maze(newx-1, newy, maze, visited_array, n, path+"U", output_path);
        visited_array[newx-1][newy]=0;
    }
    
    
}

vector<string> rat_in_a_maze(vector<vector<int>> &maze, int n){
    if(maze[0][0]==0){
        return {"Not Applicable"};
    }
    
    vector<vector<int>> visited_array(n,vector<int>(n,0));
    vector<string> output_path;
    string path="";
    visited_array[0][0]=1;
    solve_maze(0, 0, maze, visited_array,n, path, output_path);
    return output_path;
}
int main()
{
    cout<<"Rat in a Maze"<<endl;
    vector<vector<int>> maze;
    int n=4;
    maze.push_back({1, 0,0,0});
    maze.push_back({1,1,0,1});
    maze.push_back({1,1,0,0});
    maze.push_back({0,1,1,1});
    
    vector<string> output_path=rat_in_a_maze(maze, n);
    
    for(string &m: output_path){
        cout<<m<<" ";
    }
    return 0;
}