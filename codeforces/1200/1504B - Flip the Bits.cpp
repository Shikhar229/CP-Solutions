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
// TC :- O(n) or O(nlogn)





// O(n) or O(nlogn) ->     think of-> sorting
                                // ->monotonocity(binary search)
                                // ->priority queue
// --------------------------/



// Observation :
// no. of selection even aaye then 
// no change 
// if no. of selection odd aaye then 
// change aayega 
// 0 -> 1
// 1 -> 0 
// whenever group is changing then I should have 
// at that index a valid index i 
// if it is present in whole array 
// is satisfied then yes
// otherwise no(if it fails in any case )





// -----solve-----
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    if(s == t){
        cout << "YES\n";
        return;
    }

    vector<bool>valid(n,false);
    int count0 = 0;
    int count1 = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '0'){
            count0++;

        }
        else{
            count1++;

        }
        if(count0 == count1){
            valid[i] = true;
        }

    }
    // for(int i = 0;i < n; i++){
    //     cout << valid[i] <<  " ";
    // }
    // cout << endl;


    // OK valid indeces are marked now i have to go through the string 
    bool same = true;
    // same = false 
    // change waali sequence 
    // if same == true; then it is same wali sequence 
    bool found = false;
    for(int i = n-1; i >= 0;i--){
        // cout << "idx: " << i << endl;
        if(same){
            // same wali chal rahi thi
            if(s[i] !=t[i]){
                if(!valid[i]){
                    found =true;
                    break;

                }
                else{
                    same = false;
                    continue;
                }

            }  
            else{
                continue;
            } 
        }
        else{
            if(s[i] == t[i]){
                if(!valid[i]){
                    found =true;
                    break;
                }
                else{
                    same = true;
                    continue;
                }

            }
            else{
                continue;
            }
        

        }
    }
    if(!found){
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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

    return 0;
}