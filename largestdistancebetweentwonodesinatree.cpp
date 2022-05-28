/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the tree.
*/

void largestDistanceHelper(vector<vector<int>> &tree, vector<int> &height, int node, int parent, int &ans)
{
    // "maxHeight1" and "maxHeight2" stores the largest and second largest
    // height of children of current node, respectively.
    int maxHeight1, maxHeight2;

    maxHeight1 = maxHeight2 = 0;

    // Iterate over the children of the current node;
    for (int &child : tree[node])
    {
        if (child == parent)
            continue;

        // Recursively calculate the diameter for "child" nodes.
        largestDistanceHelper(tree, height, child, node, ans);

        // Update height of the current node, if required.
        height[node] = max(height[node], height[child] + 1);

        // Update the stored max height of the children, if required.
        if (height[child] >= maxHeight1)
        {
            maxHeight2 = maxHeight1;
            maxHeight1 = height[child];
        }
        else if (height[child] > maxHeight2)
        {
            maxHeight2 = height[child];
        }
    }

    // Update the diameter/distance between two nodes, if required.
    ans = max(ans, height[node] - 1);
    ans = max(ans, maxHeight1 + maxHeight2);
}

int largestDistance(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> tree(n);

    for (vector<int> &edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    int ans = 0;

    vector<int> height(n, 1);

    largestDistanceHelper(tree, height, 0, -1, ans);

    return ans;
}
