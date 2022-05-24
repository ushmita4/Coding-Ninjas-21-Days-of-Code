/*
    Time Complexity: O(N * M)
    Space Complexity: O(N + M)
    
    Where 'N' is the number of rows and 'M' is the number of columns of grid 'ARR'.
*/

int totalConnectedComp(vector < vector < int > > arr, int n, int m) {
    // Variable to store the answer.
    int ans = 0;
    int rowCtr[n];
    int columnCtr[m];

    // Precompute the total computers for each column.
    for (int j = 0; j < m; j++) {
        columnCtr[j] = 0;
    
        for (int i = 0; i < n; i++) {
            columnCtr[j] += arr[i][j];
        }
    }

    // Precompute the total computers for each row.
    for (int i = 0; i < n; i++) {
        rowCtr[i] = 0;

        for (int j = 0; j < m; j++) {
            rowCtr[i] += arr[i][j];
        }
    }

    // Iterate each grid element.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If given grid has computer and also any other is present in same row or column.
            if (arr[i][j] == 1 && (rowCtr[i] > 1 || columnCtr[j] > 1)) {
                ans++;
            }
        }
    }
    return ans;
}
