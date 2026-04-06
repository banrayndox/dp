#include <bits/stdc++.h>
using namespace std;
bool tab(vector<int> array, int target){
    int n = array.size();
    vector<vector<int>> dp (n+1, vector<int>(target+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            int num = array[i-1];
            if(num<=j) {
                dp[i][j] = max(dp[i-1][j], num+dp[i-1][j-num]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    
    return dp[n][target] == target;
    
}
int main(){
    
    vector<int> array = {4,2,7,1,3};
    int target = 10;
    int n = 5;
    cout << tab(array, target) << endl;
    
    
    
    
    return 0;
}
