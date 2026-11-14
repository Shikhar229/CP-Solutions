#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

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
// choose group of k ones and how many left and right zero's before a nearest one 
// left me = x , right me = y
// left me 0 -> y me ->y
// left me 1 -> y me ->y
// left me 2 -> y me ->y
// ...
// ..
// ..
// left me m -> right me y
// x*y

// the whole problem is now ->
// where s[i] = 1 -> precompute minimam position of where I get next 1  or maximum position of 0 


// Hypothesis


// Conclusion

// for any 1 at any postition 
// 




// -----solve-----
void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int>one;
    one.pb(-1);

    bool allzero = true;
    for(int i = 0 ; i < s.size(); i++){
        int x = s[i]-'0';
        if(x == 1) {
            one.pb(i);
            allzero = false;
        }
        
        
    }
    one.pb(s.size());
    ll ans = 0;
    int n= one.size();
    if(k==0){
        if(allzero){
            ll m = s.size();
            ans += (m * (m+1))/2 ;
        }
        else{
            for(int i = 1; i < n; i++){
            ll left  = one[i]-one[i-1]-1;
            ans += ((left*(left+1)))/2;
        }

        }
    }

        
    
    if(k >= 1){
        for(int i = 1; i +k<n; i++){
        ll left = one[i]-one[i-1];
        ll right = one[i+k]-one[i+k-1];
        ans += (left*right);

    }

    }
    
    cout << ans << "\n";
    // store {index, left me kitne zero , right me kitne zero}
    
    
    


}

// ------Main----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // // int t;
    // // cin >> t;
    // // while (t--) {
    // //     solve();
    // // }

    solve();

    return 0;
}