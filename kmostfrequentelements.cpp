/*
    Time Complexity: O(N * LOG(N))
    Space Complexity: O(N)

    where 'N' is the size of the input array.
*/

#include<map>
#include<queue>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    if (k == n) {
        return arr;
    }

    map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr) {

        mp[ele]++;
    }

    // Elements in heap will be sorted in descending order
    // according to the frequency of the element.
    priority_queue<pair<int,int>> heap;

    // Build heap of maximum size 'K'.
    for (auto x : mp) {
        heap.push({x.second, x.first});
    }

    vector<int> ans(k);

    // Build output array.
    for (int i = 0; i < k; i++) {

        ans[i] = heap.top().second;
        heap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}
