#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> array(n+1);
    vector<int> prefix(n+1,0);
    for(int i=1; i<=n; i++){
        cin >> array[i];
        prefix[i]= prefix[i-1] + array[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl;
    }
    
    
    
    
    
    return 0;
}
