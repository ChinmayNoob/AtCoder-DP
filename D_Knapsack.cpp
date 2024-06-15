#include<bits/stdc++.h>
using namespace std;
#define int long long

int knapsack(vector<int>& wt, vector<int>& val, int n, int w) {
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;++j){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j>=wt[i]){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-wt[i]]+val[i]);
            }
        }
    }
    return dp[n][w];


}


int32_t main(){
    int n,w;
    cin>>n>>w;
    // vector<pair<int,int>> arr(n);
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++){
        int wgt,value;
        cin>>wgt>>value;
        wt[i]=wgt;
        val[i]=value;
        // cin>>arr[i].first>>arr[i].second;

    }

    //max possible sum 


    int ans=knapsack(wt,val,n,w);
    cout<<ans<<endl;



}
