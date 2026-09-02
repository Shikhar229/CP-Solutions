#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
    cin >> n;
    vector<int>a(n);
    
    for(int i= 0;i < n; i++){
        cin >> a[i];
    }
    
    unordered_map<int,int>mp;
    
    for(int i = 0;i < n; i++){
        int x = 31- __builtin_clz(a[i]);
        mp[x]++;
        
    }
    
    int count = 0;
    for(auto it :mp){
        count = max(count,it.second);
    }
    cout << count << endl;
	    
	}


    

}
