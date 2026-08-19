#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
// 	size of the array is 2*n

// swap ai with a2N+1-i
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(2*n);
        for(int i = 0;i <2*n; i++){
            cin >> a[i];
        }
        long long sum = 0;
        for(int i = 0;i < n ;i++){
            sum += max(a[i],a[2*n-i-1]);
        }
        cout << sum << endl;
    }
    
    

}
