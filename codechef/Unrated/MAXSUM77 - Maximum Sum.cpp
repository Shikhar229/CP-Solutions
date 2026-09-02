#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    vector<int>a(n);
	    for(int i= 0;i < n; i++){
	        cin >> a[i];
	    }
	    vector<int>pref(n);
	    pref[0] = a[0];
	    for(int j = 1;j < n; j++){
	        pref[j] = pref[j-1] + a[j];
	    }
	    int maxi = INT_MIN;
	    for(int j = n-k-1; j < n ;j++){
	        int s = j-(n-k)+1;
	        
	        if(s == 0){
	            maxi = max(maxi,pref[j]);
	            
	        }
	        else{
	            maxi = max(maxi, pref[j]- pref[s-1]);
	        }
	    }
	    cout << maxi << endl;
	   
	    
	    
	}
}
