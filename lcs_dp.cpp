#include <bits/stdc++.h>
using namespace std;

int lcsRec(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    if(n== 0 || m==0) return 0;
    
    if(str1[n-1]==str2[m-1]){
        return lcsRec(str1.substr(0,n-1), str2.substr(0,m-1)) + 1;
    }
    else{
        
        int ans1 = lcsRec(str1.substr(0,n-1), str2);
        int ans2 = lcsRec(str1, str2.substr(0,m-1));
        return max(ans1, ans2);
        
    }
    
    
}

int lcsMem(string str1, string str2, vector<vector<int>> &dp){
    int n = str1.size();
    int m = str2.size();
    if(n== 0 || m==0) return 0;
    
    
    if(dp[n][m] !=-1 ){
        return dp[n][m];
    }
    
    if(str1[n-1]==str2[m-1]){
        dp[n][m] = lcsMem(str1.substr(0,n-1), str2.substr(0,m-1), dp) + 1;
    }
    else{
        
        int ans1 = lcsMem(str1.substr(0,n-1), str2, dp);
        int ans2 = lcsMem(str1, str2.substr(0,m-1), dp);
        dp[n][m] = max(ans1, ans2);
        
    }
    return dp[n][m];
    
}

int lcsTab(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1]==str2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // traceback
    int i = n, j = m;
    string result = "";
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            result+=str1[i-1];
            i--; j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else j--;
        }
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    
    return dp[n][m];
    
}

int main(){
    
    
    string string1 = "Rakib";
    string string2 = "bbakiaa";
    int n = string1.size();
    int m = string2.size();
    
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    // cout << lcsMem(string1, string2, dp);
    cout << lcsTab(string1, string2);
    
    
    
    
    return 0;
}
