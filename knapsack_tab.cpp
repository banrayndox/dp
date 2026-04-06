#include <bits/stdc++.h>
using namespace std;

int tab(vector<int> wt, vector<int>val, int n, int w){
      vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
     for(int i=1; i<=n; i++){
         for(int j=1; j<=w; j++){
             int item_wt = wt[i-1];
             int item_val = val[i-1];
             
             if(item_wt<=j){
                 dp[i][j] = max(item_val+dp[i-1][j-item_wt], dp[i-1][j]);

             }else{
                 dp[i][j] = dp[i-1][j];
             }
             cout << dp[i][j] <<" ";
             
         }
         cout << endl << endl;
     }
     for(int i=0; i<=n; i++){
         for(int j=0; j<=w; j++){
             cout << dp[i][j] << " ";
         }
         cout << endl;
     }
    
    return dp[n][w];
    
}

int main(){
    vector<int> val = {14,15,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;
    cout << tab(wt,val,n,w) << endl;
    
    return 0;
}
