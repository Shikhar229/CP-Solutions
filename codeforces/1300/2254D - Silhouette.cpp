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
    int n; cin >> n;
    vector<ll>a(n);
    vector<vector<ll>>b;
    for(int i = 0;i < n; i++) {
        cin >> a[i];
        b.push_back({a[i],i});
    }
    sort(b.begin(),b.end());
    
    int i = 0;

    ll prev = 0;
    // cout << "Call:\n";
    ll sum = 0;

    while(i < b.size()){
        ll val = b[i][0];
        int j = i;
        while(j < n && b[j][0] == val ){
            j++;
        }
        // if(j >= n){
        //     cout << -1 << endl;
        //     return;
        // }
        // cout << "idx " << i << " " << j << endl;
       
        
        
        int count = j-i;
        ll curr;
        if(val != sum){
            cout << -1 << endl;
            return;
        }

        if(j == n){
            curr = prev + 1;
        }
        else{
            ll nextB = b[j][0];
            
            curr = (nextB - val);
            if(curr < 0){
                cout << -1 << endl;
                return;
            }
            if(curr % count != 0){
                cout << -1 << endl;
                return;
            }
            curr = curr/count;
            
        }
        if(curr <= prev){
            cout << -1 << endl;
            return;
        }
        while(i < j){
            a[b[i][1]] = curr;
            i++;
        }

        sum += 1LL * curr * count;
       
        prev  = curr;
        
    }
    

    for(int i = 0;i < n; i++){
        cout << a[i] << " ";
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