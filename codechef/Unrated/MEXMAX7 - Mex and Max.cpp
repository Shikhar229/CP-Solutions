#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 998244353;
int dp[101][101];


int f(int pos, int mex, int max_pos, vector<int>&arr){
    if(pos == max_pos){
        return abs(mex- arr[max_pos]) <= 1;
    }
    
    int &ans = dp[pos][mex];
    if(ans  != -1){
        return ans;
    }
    
    int ans1 = f(pos+1, mex, max_pos,arr);
    int ans2;
    
    if(arr[pos] == mex){
        ans2 = f(pos+1, mex+1, max_pos, arr);
    }
    else{
        ans2 = f(pos+1, mex, max_pos, arr);
    }
    ans = (ans1+ans2)% mod;
    return dp[pos][mex] = ans;
}



int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0;i <n; i++){
	        cin >> arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    ll ans = 0;
	    
	    for(int max_pos = 0; max_pos < n; max_pos++){
	        memset(dp,-1,sizeof(dp));
	        ans = (ans+f(0,0,max_pos,arr))% mod;
	    }
	    cout<< ans << "\n";
	    
	}

}
