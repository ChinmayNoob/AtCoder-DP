#include<bits/stdc++.h>
using namespace std;

int helper(int i, vector<int> &arr, vector<int> &dp) {
    // Base Case 
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int smallJump = helper(i - 1, arr, dp) + abs(arr[i] - arr[i - 1]);
    int bigJump = INT_MAX;
    if (i > 1) {
        bigJump = helper(i - 2, arr, dp) + abs(arr[i] - arr[i - 2]);
    }
    return dp[i] = min(smallJump, bigJump);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, -1);
    int ans = helper(n - 1, arr, dp);
    cout << ans << endl;

    return 0;
}
