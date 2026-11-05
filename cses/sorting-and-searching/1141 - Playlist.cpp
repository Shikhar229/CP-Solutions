#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int>a(n);

    map<int,int>mp;

    int ans = 0;
    int l = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        
        while(mp[a[i]] > 0){
            mp[a[l]]--;
            l++;
            
            
        }
        mp[a[i]]++;
        ans = max(ans,i-l+1); 
        
    }
    cout << ans << endl;
    
}