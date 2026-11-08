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
// minimize the maximum possible gap value 


// Observation : 


// Hypothesis
// Binary search
// fm and second maximum is important 
// agar away hai to fm par jaake check karo jo jisse difference minimize ho wo wo number ko double karke check karo

// agar fm and second maximum adjacent hai to 
// agar beech wala number hai jisko multiply karenge then dono par farak padega nahi to keval fm then do like case1 as mentioned above 


// Conclusion

int fn(vector<int>&a, int j){
    int n = a.size();
    vector<int>suff(n);
    
    suff[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        suff[i] = max(suff[i+1],abs(a[i]-a[i+1]));

    }
    int seg = 0;
    int l = 0;
    for(int i = 1;i < j ;i++){
        l = max(l,abs(a[i]-a[i-1]));

    }
    int ans = 1e9;

    for(int r = j ; r < n; r++){
        if(r > j){
            seg = max(seg, abs(a[r]-a[r-1]));
        }

        int pos = max(l,2*seg);
        if(r+1 < n){
            pos = max(pos,abs(2*a[j]-a[r+1]));
        }
        if(r+1 < n){
            pos = max(pos,suff[r+1]);
        }
        if(j-1 >= 0){
            pos = max(pos,abs(a[j-1]-2*a[r]));
        }
        ans = min(ans,pos);

    }
    return ans;
    
}




// -----solve-----
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    int ans = 0, j = 0;
    for (int i = 1; i < n; i++){
        int pos = abs(a[i] - a[i - 1]);
        if (pos > ans){
            ans = pos;
            j = i;
        }
    }
 
    ans = min(ans, fn(a, j));
 
    reverse(a.begin(), a.end());
 
    ans = min(ans, fn(a, n - j));
 
    cout << ans << '\n';
    

    
    


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