/*

    Time Complexity : O(N*M)
    Space Complexity : O(N*M)

    where N is the number of rows in the 'GRID' and
    M is the number of columns in the 'GRID'.

*/

class ArticulationPoint {
   public:
    bool cutPoint;              // Set it to true in the DFS call if an articulation point is present.
    vector<vector<bool>> seen;  // Use it to mark the visited nodes in DFS.
    vector<vector<int>> tin;    // Use it to store the entry time during DFS call.
    vector<vector<int>> low;    // Use 'low[i]' to store the earliest node that is connected to 'i' (including 'i').
    int timer;                  // Use it to keep track of time during DFS call.
    int n, m;                   // Dimensions of the 'GRID'.

    ArticulationPoint(int n, int m) : n(n), m(m) {
        // Initializations before the DFS call.
        cutPoint = false;
        timer = 0;
        seen.resize(n, vector<bool>(m, false));
        tin.resize(n, vector<int>(m, -1));
        low.resize(n, vector<int>(m, -1));
    }

    // The DFS traversal function (Current cell: '(x, y)', Parent cell: '(pX, pY)')
    void dfs(int x, int y, int pX, int pY, vector<vector<int>>& grid) {
        // Add 'dir[i]' to move to adjacent cell.
        static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        seen[x][y] = true;                // Mark the city at '(x, y)' as visited.
        tin[x][y] = low[x][y] = timer++;  // Set the entry time.

        // Count the number of children in the DFS tree.
        // Use it to check if the root is an articulation point.
        int children = 0;

        for (int i = 0; i < 4; i++) {
            // Position of the adjacent cell.
            int newX = x + dir[i][0], newY = y + dir[i][1];

            // Continue, if the adjacent cell is an invalid cell or the parent cell.
            if (newX < 0 || newX >= n || newY < 0 || newY >= m || (newX == pX && newY == pY)) {
                continue;
            }

            // If there is a city at the adjacent cell.
            if (grid[newX][newY]) {
                // If already visited, then there is a back edge so update 'low[x][y]' directly.
                if (seen[newX][newY]) {
                    low[x][y] = min(low[x][y], tin[newX][newY]);
                }
                // Traverse the child subtree (in the DFS tree) and then update 'low[x][y]'.
                else {
                    dfs(newX, newY, x, y, grid);
                    low[x][y] = min(low[x][y], low[newX][newY]);

                    // If no node from the child subtree has a back edge.
                    if (low[newX][newY] >= tin[x][y] && pX != -1) {
                        cutPoint = true;
                    }
                    children++;
                }
            }

            // If root node has more than two children in the DFS tree then it is an articulation point.
            if (pX == -1 && children > 1) {
                cutPoint = true;
            }
        }
    }
};

int minCities(vector<vector<int>>& grid, int n, int m) {
    int count = 0;

    // Count the cities in 'GRID'.
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            count += grid[x][y];
        }
    }
    if (count <= 1) {  // If there are less than two cities.
        return count;
    }

    count = 0;  // Use it to count the number of states.

    ArticulationPoint ap(n, m);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            // If '(x, y)' is a city and it has not been visited yet.
            if (grid[x][y] && !ap.seen[x][y]) {
                count++;
                if (count > 1) {  // If there is more than one state, then the asnwer is '0'.
                    return 0;
                }

                // Find if an articulation point is present and mark the cities connected to '(x, y)'.
                ap.dfs(x, y, -1, -1, grid);
            }
        }
    }

    if (ap.cutPoint) {  // If an articulation point is present, then the answer is '1'.
        return 1;
    }

    return 2;  // If '0' and '1' are not the answers, then '2' is always a valid answer.
}
