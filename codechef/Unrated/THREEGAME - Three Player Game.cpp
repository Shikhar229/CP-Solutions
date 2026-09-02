#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    if(n == 1) cout << 1 << endl;
	    else{
	        if(n % 2 == 1){
	            cout << n + (n-1)/2<< endl;
	        }
	        else{
	            cout << (3 * (n/2)) + 1<< endl;
	        }
	    }
	  
	  
	    
	}

}
