// variation of knapsack unbound - count ways
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int a ,b;
    char ch;
    while(cin >> a>> ch >> b){
        int amount = 0;
        if(a==0 && b==0) break;
        else amount = a*100 +b;
vector<int> coin = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int n = coin.size();
vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
// int m = amount;
dp[0][0] = 1;
for(int i=1; i<=n; i++){
    for(int j=0; j<=amount; j++){
        if(coin[i-1]<=j){
            dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
        }else{
            dp[i][j] = dp[i-1][j];
        }
    }
}
        
        cout << dp[n][amount] << endl;
    }
    
    
    
    
    
    return 0;
}
