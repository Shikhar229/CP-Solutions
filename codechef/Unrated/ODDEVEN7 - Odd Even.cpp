#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >>n;
	    vector<int>a(n);
	    
	    int odd = 0;
	    int even = 0;
	    for(int i = 0;i < n; i++){
	        cin >> a[i];
	        if(a[i]%2 == 1){
	            odd++;
	            a[i] = -1;
	            
	        }
	        else{
	            even++;
	            a[i]  = 1;
	            
	            
	        }
	    }
	    if(odd == even){
	        cout << 2*min(odd,even) << endl;;
	    }
	    else{
	        cout << 2* min(odd,even)+ 1<<endl;
	    }
	    
	}

}
