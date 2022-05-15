/*
    Time Complexity: O(log(N))
    Space Complexity: O(log(N))

    where 'N' is the value of the label (given node).
*/

vector <int> findPathInZigZagTree(int label) {

    vector <int> result;
    int parent = label;
    result.insert(result.begin(), label);

    while (parent != 1) {
        int depth = log(parent) / log(2);
        int offset = pow(2, depth + 1) - 1 - parent;
        parent = (pow(2, depth) + offset) / 2;
        result.insert(result.begin(), parent);
    }
    return result;

}
