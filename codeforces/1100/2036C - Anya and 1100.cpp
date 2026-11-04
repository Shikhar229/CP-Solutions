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

    string s;
    cin >> s;
    int n = s.size();
    string t = "1100";

  

    int count = 0;
    int pos = 0;

    while ((pos = s.find(t, pos)) != string::npos) {
        count++;
        pos++; 
    }
    int q;
    cin>> q;
    while(q--){
        int i,v;
        cin >> i >> v;
        i--;
        if(s[i]-'0' == v){
            if(count > 0){
                cout << "YES\n";
                continue;
            }
            else{
                cout << "NO\n";
                continue;
            }
        }

        
        if(v == 0){
            // 1 bana raha hai to kya karen
            if(i+3 < n){
                if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
                    count--;
                }

            }
            if(i+2 < n && i-1 >= 0){
                if(s[i-1] == '1' && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0'){
                    count--;
                }

            }
            if(i-2>=0&&i+1<n){
                if(s[i-2]=='1'&&s[i-1]=='1'&&s[i+1]=='0') count++;
            }
            

            if(i-3 >= 0){
                if(s[i-1] == '0'&& s[i-2]  == '1' && s[i-3] == '1'){
                    count++;
                }
            }
            s[i] = '0';
            
        }
        else{
            //0 ko 1 bana rahe

            if(i-3 >= 0){
                if(s[i] == '0' && s[i-1] == '0' && s[i-2] == '1' && s[i-3] == '1'){
                    count--;
                }
            }
            if(i-2 >= 0 && i+1 < n){
                if(s[i] == '0' && s[i-1] == '1' && s[i-2] == '1' && s[i+1] == '0'){
                    count--;
                }
            }
            if(i-1>=0&&i+2<n){
                if(s[i-1]=='1'&&s[i+1]=='0'&&s[i+2]=='0') count++;
            }
            
            
            if(i+3 < n){
                if(s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
                    count++;
                }

            }
            s[i] = '1';
        }
        if(count > 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
       
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