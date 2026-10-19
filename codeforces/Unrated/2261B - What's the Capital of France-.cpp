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
    // bitwise or of the rating of all restaurant
    // 1 | 1 = 1
    // 0 | 1 = 1
    // 1| 0 = 1
    // agar 1 baar increase karnege 
    // har number par jayenge 
    // loweset signinficant bit par jayenge aur uske right wale jitne bhi bit hai unko change karnege

    // highest set bit se start karte hai 
    // agar highest set bit me even number of ones hai to 0 ho jayega highest bit
    // we want not to destroy it we would iterate over the numbers
    // check any number is smaller than that if yes ok I will 
    // make it after adjacent element 

    ll n;
    cin >> n;
    
    ll maxi = LLONG_MIN;
    ll mini = LLONG_MAX;
    for(int i = 0;i < n; i++){
        ll x;
        cin >> x;
        maxi = max(maxi,x);
        mini = min(mini, x);
    }

    if(mini == maxi){
        cout << maxi <<"\n";
        return;
    }
    ll k= 63- __builtin_clzll(maxi^mini);
    // highest set bit jaha par different hai 
    // maximum and minimum
    ll m = 63 - __builtin_clzll(maxi);
    
    if(k == m){
        // m-63 maximum ka highest set bit
        // k = jaha par maximum and minimum different hai 
        // uska highest set bit
        // equal nahi hai to increase karo 
       cout << ((1LL << (m+1))-1) << "\n";

    }
    else{
        // dono same posisition par hai then 
        // what we can do 
        ll y = (1LL << (k+1))-1;
        cout << (y|maxi) << "\n";
    }
    

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