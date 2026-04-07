#include <bits/stdc++.h>
using namespace std;
int main(){
    
int n,m;
cin >> n >> m;
vector<vector<int>> matrix (n+1, vector<int>(m+1, 0));
vector<vector<int>> prefix (n+1, vector<int>(m+1, 0));
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        cin >> matrix[i][j];
        prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]+matrix[i][j]-prefix[i-1][j-1];
    }
}
int q;
cin >> q;
while(q--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << ( prefix[c][d]+prefix[a-1][b-1]-prefix[a-1][d]-prefix[c][b-1] ) << endl;
}

    
    
    
    return 0;
}
