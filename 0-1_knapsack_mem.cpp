#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>>&dp){
    
    if(w==0 || n==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w){
        //include
        int ans1 = calc(val, wt, w-wt[n-1], n-1, dp) + val[n-1];
        //exclude
        int ans2 = calc(val, wt, w, n-1, dp);
        
        dp[n][w] = max(ans1, ans2);
        
    }else{
        //exclude
        dp[n][w] = calc(val, wt, w, n-1, dp);
    }
    return dp[n][w];
    
    
}

int main(){
    
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;
    vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
    int result = calc(val, wt, w, n, dp);
    cout << result << endl;
    for(auto x: dp){
        for(auto z: x) cout << z << " ";
        cout << "\n";
    }
    
    return 0;
}
