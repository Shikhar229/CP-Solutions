#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;



// ----Binary exponentiation---
ll binpow(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

// ------Sieve & Primes Computation-----
const int MAXA =2000005;
vector<bool>isPrime;
vector<int>prime;

void sieve() {
	isPrime.assign(MAXA, true);
	if(MAXA >= 0) {
		isPrime[0] = false;

	}
	if(MAXA >=1 ) {
		isPrime[1] = false;
	}
	for(int i = 2 ; i*i< MAXA ; i++) {
		if(isPrime[i]) {
			for(int j  = i*i ; j <MAXA ; j+= i) {
				isPrime[j] = false;
			}
		}
	}

    for(int i = 0; i< MAXA ; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }

}

// -------GCD -------
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

// --------- ncr ------
ll ncr(ll n, ll r) {
    if (r > n - r)
        r = n - r;

    ll ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }

    return ans;
}

// -------- Prime Check ----
bool checkPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i <= n / i; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Expected Complexity : -




// O(n) or O(nlogn) ->     think of-> sorting
                                // ->monotonocity(binary search)
                                // ->priority queue
// --------------------------/



// Observation : 





// -----solve-----
void solve() {
    int n;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i = 0;i< n; i++){
        string s;
        cin >> s;
        for(int j = 0;j < s.size();j++){
            int x = s[j] -'0';
            a[i][j] = x;
        }
    }
    int ans = 0;

    for(int layer = 0; layer < n/2; layer++){

        for(int j = layer ;j < n-1-layer;j++){
            // dekho top wala 
            // i fixed rahega j change hoga
            // i tab change hoga jab layer change hoga
            // and layer ++ then i++
            int top = a[layer][j];

            // right fixed hai layer change right change
            // n-1-layer
            int left = a[j][n-1-layer];

            // bottom 
            // bottom wala jab layer change hoga tab hai
            int bottom = a[n-1-layer][n-1-j];
            
            int right = a[n-1-j][layer];

            int one = 0;
            int zero = 0;

            if(top == 1)one++;
            else zero++;

            if(bottom == 1) one++;
            else zero++;

            if(right == 1)one++;
            else zero++;

            if(left == 1) one++;
            else zero++;
            
            if(one <= zero){
                 a[layer][j] = 0;
                 a[n-1-j][layer] = 0;
                 a[n-1-layer][n-1-j] = 0;
                 a[j][n-1-layer] = 0;

            } 
            else{
                a[layer][j] = 1;
                 a[n-1-j][layer] = 1;
                 a[n-1-layer][n-1-j] = 1;
                 a[j][n-1-layer] = 1;

            }  
            ans += min(one,zero);
           
            
        }

    }
    cout << ans << "\n";
    
    


}

// ------Main----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

    return 0;
} 