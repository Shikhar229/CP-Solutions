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



// Small Observation : 
// [5,6,1,1]
// i = 0 : 5
// i = 1 : 6
// i = 2 : 1
// i = 3 : 1 (same as i = 2)

// i-1 is bigger than i
// left wale ko pehle bada banayenge then 
// i me aisa number add karenge jo ai-1 se bada Ho

// [5,6,1,1]
// [1,1,1,1]
// dif 1
// if I choose x = 4  equal ho jaenge fir add karna padega 0, 1
// which is smallere tha x 
// choose x = 3 \ 4 4 1 1 -> add karna hoga 1 ,2 both bade
// choose x = 2 \ [3,3,1,1] - > add karna hoga 2,3  which is smaller 
// choose 1 usme to kcuh add hi nahi hoga lmao then the better choice is build from left to right
// [1,1,0,0]




// Hypothesis


// Conclusion





// -----solve-----
void solve() {
    // choose an x > min(a)
    int n;
    cin >> n;
    vector<int>b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int mini = b[0];

    bool found = false;
    for(int i = 1 ; i < n; i++){
        if(b[i] >= 2*mini ){
            found = true;
            break;
        }
        mini =min(mini,b[i]);
    }
    if(found) cout << "NO\n";
    else cout  << "YES\n";

    
    


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