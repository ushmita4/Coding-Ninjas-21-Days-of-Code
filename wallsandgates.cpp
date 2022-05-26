/*
    Time Complexity: O(N * M)
    Space complexity: O(N*M)

    Where 'N' is the number of rows and 'M' is the number of columns in the matrix.

 */

#include <limits.h>
#include <queue>

// Integer variables to denote the type of the cell
int EMPTY = INT_MAX;
int GATE = 0;
int WALL = -1;

// Direction arrays for up, down, left, and right
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) 
{
    queue<pair<int, int>> q;
    
    // Add all the gates in the queue
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] == GATE) 
            {
                q.push({i, j});
            }
        }
    }

    while (q.size() > 0) 
    {
        pair<int, int> cell = q.front();
        q.pop();
        int curRow = cell.first;
        int curCol = cell.second;
        
        // Traverse on all four neighbors
        for (int k = 0; k < 4; ++k) 
        {
            int r = curRow + dx[k];
            int c = curCol + dy[k];
            
            // If cell is invalid or it is not empty then we skip this cell
            if (r < 0 || c < 0 || r >= n || c >= m || a[r][c] != EMPTY) 
            {
                continue;
            }
            
            // We update the distance of neighbor cell and it to our queue
            a[r][c] = a[curRow][curCol] + 1;
            q.push({r, c});
        }
    }
    
    // Return the modified matrix
    return a;
}
