#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t--){
	    int n;
	    long long k;
	    
	    cin >> n>>k;
	    vector<long long>a(n);
	    for(int i = 0;i < n; i++){
	        cin >> a[i];
	    }
	   // one item free
	   //sequence me buy karna hai
	   //1 to n 
	   //prefix try
	   vector<long long>pref(n);
	   pref[0] = a[0];
	   for(int i = 1;i < n; i++){
	       pref[i] = pref[i-1]+ a[i];
	   }
	   long long maxi = a[0];
	   int idx = -1;
	   
	   for(int i = 0;i < n; i++){
	       maxi = max(maxi,a[i]);
	       long long x = pref[i]- maxi;
	       if(x <= k){
	           idx = i;
	       }
	       
	       
	       
	   }
	   cout << idx+1<<endl;
	   
	   
	}
	

}
