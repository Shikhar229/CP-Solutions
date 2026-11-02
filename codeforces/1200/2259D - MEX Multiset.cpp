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
// t1 t2 >= t3
// t3 >= t1 and t3 >= t2
// that means right term should be less than both of the left term
// means atleast one should make like that 
// whose mex is less than equal to two other mex
// then it would be possible 
// ek mex dono se choota ya barabbar kar denge 


// Hypothesis

// if atleast two zero would present then it is always possible to do that 
// only one zero then not possible in any way 
// if zero not present then always possible 



// Conclusion

// count no. of zero 
// no. of zero = 0 always possible
// no. of zero = 1 not possible
// no. of zero >= 2 always possible





// -----solve-----
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);

    int count = 0;
    for(int i = 0;i< n ;i++){
        cin>> a[i];
        if(a[i] == 0){
            count++;
        }
    }
    if(count == 0){
        cout << "YES\n";
        string s = "";
        for(int i = 0;i < n; i++){
            s.push_back('A');
        }
        cout << s << "\n";
    }
    else if(count  == 1){
        cout << "NO\n";
        

    }
    else{
        cout << "YES\n";
        vector<int>pos;
        bool first = false;
        bool second = false;
        string s = "";

        for(int i = 0;i < n; i++){
            if(a[i] != 0){
                s.push_back('C');
            }
            else{
                if(!first){
                    s.push_back('A');
                    first = true;
                }
                else{
                    s.push_back('B');
                }
            }
        }
        cout << s << endl;
        
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