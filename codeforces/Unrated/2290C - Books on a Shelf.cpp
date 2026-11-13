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
    int n;
    cin >> n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int>b(n,-1);
    int i = 0;
    auto it = mp.begin();
    while(it != mp.end()){
        b[i] = it->first;
        it->second--;
        if(it->second == 0){
            it =mp.erase(it);
        }
        else{
            ++it;

        }
        i++;
    
    }
    i = n-1;
    it = mp.begin();
    while(it != mp.end()){
        b[i] = it->first;
        it->second--;
        if(it->second == 0){
            it =mp.erase(it);
        }
        else{
            ++it;

        }
        i--;
    }
    it = mp.begin();
    for(int i = 0; i < n; i++){
        if(b[i] == -1){
            b[i] = it->first;
            it->second--;
            if(it->second == 0){
                it = mp.erase(it);
            }
        }
    }
    int k = 0;
    int ans = 0;
    int ml = -1;

    while(k < n && b[k] > ml){
        ans++;
        ml = b[k];
        k++;
    }

    int j = n-1;
    int mr = -1;
    
  
    while(j >= k&& b[j] > mr){
        ans++;
        mr = b[j];
        j--;
    }
    
    // cout << "pehle: " << ans << endl;
    
    cout << ans << endl;
    for(int j = 0; j < n; j++){
        cout << b[j] << " ";
    }
    cout << endl;
    


    


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