#include<bits/stdc++.h>
using namespace std;

int helper(int i, vector<int> &arr, vector<int> &dp,int k) {
    // Base Case 
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int minSteps =INT_MAX;

    for(int j=1;j<=k;j++){
    	if(i-j>=0){
    		int temp =helper(i-j,arr,dp,k)+abs(arr[i]-arr[i-j]);
    		minSteps=min(minSteps,temp);
    	}
    }
    return dp[i]=minSteps;
}


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, -1);
    int ans = helper(n - 1, arr, dp , k);
    cout << ans << endl;

    return 0;
}
