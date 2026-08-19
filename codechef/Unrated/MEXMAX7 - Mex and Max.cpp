#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int power(int y){
    int ans = 1;
    int x = 2;
    while(y > 0){
        if(y & 1){
            ans = (1LL * ans * x) % mod;
            
            
        }
        x = (1LL * x * x)% mod;
            y >>= 1;
    }
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int>a(n);
	    
	    map<int,int>mp;
	    for(int i = 0;i < n; i++){
	        cin >> a[i];
	        mp[a[i]]++;
	    }
	   // |mex(b) - max(b)| <= 1
	   //minimum non negative integer not present in b,
	   //maximum non negative integer not present in b
	   //x-y ==0
	   //when x == y
	   //x-y == 1
	   //jab maximum element jo nahi hai wo minimum element jo hai usse ek jyada ho
	  
	   // mexB = max B galat
	   //mex B = max B + 1
	   //max B = mex B + 1
	   map<int,int>p;
	   
	   int answer = 1;
	   for(int i = 0;i <= n +1 ;i++){
	       int x = (power(mp[i])-1 + mod) % mod;
	       answer = (1LL * x * answer )% mod;
	       p[i] = answer;
	       

	       
	   }
	   
	   int ans = 0;
	   for(int i =0;i <= n; i++){
	       ans = (ans + p[i])% mod;
	   }
	   
	   for(int i = 1;i <= n ;i++){
	       int x;
	       if(i-2 >= 0){
	           x = p[i-2];
	       }
	       else{
	           x = 1;
	       }
	       int y = (power(mp[i])-1+mod)%mod;
	       int z = (1LL * x * y) % mod;
	       ans = (ans + z)% mod;
	   }
	   cout << ans << endl;
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	}

}
