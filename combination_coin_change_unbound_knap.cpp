#include <bits/stdc++.h>
using namespace std;
int main(){
    int val[]= {1,2,5};
    int n = 3;
    int target = 5;
    vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
    for(int i=1; i<=target; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            int item = val[i-1];
            if(item<=j){
                dp[i][j] = dp[i-1][j] + (dp[i][j-item] );
            }else{

                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][target] << endl;
    
    
    return 0;
}
