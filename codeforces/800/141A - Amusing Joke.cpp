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


// Hypothesis


// Conclusion





// -----solve-----
void solve() {
    // vector<int>freq(26,0);
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3 ;
    string a  = s1 + s2;
    sort(a.begin(),a.end());
    sort(s3.begin(),s3.end());
    if(a == s3){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }



}

// ------Main----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}