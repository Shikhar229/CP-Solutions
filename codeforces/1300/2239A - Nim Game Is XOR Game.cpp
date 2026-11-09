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
    for(int i = 0;i < n; i++){
        cin >> a[i];

    }

    // vector<int>bit(30,0);

    // for(int i = 0;i < n; i++){
    //     int x = a[i];
    //     // for each x go to each 
    //     for(int b = 0; b <30; b++){
    //         if(x & (1 << b)){
    //             bit[b]++;
    //         }
    //     }
    // }
    // for(int i  = 29; i >= 0; i--){
    //     cout << bit[i] << ' ';
    // }
    // cout << endl;
    // i got no. of ones in each bit 


    // if no. of one's odd-> 7
    // make 6 4 2 0
    // take 1 3 5 7 -> make zero

    // if no. of one's even -> 6
    // 6 4 2 0
    // take 0 2 4 6 -> make zero 
    
    // go to the lowest bit 
    // consider no. of possibility to make that zero 
    // left me kisi na kisi number ka 1 hoga hi for sure 

            // 0 0 1
            // 1 0 0
            // 1 0 1
            // 0 1 0
            // 1 1 0 

//no.of ones// 3 2 2 
//             2^(3-1)  2^(2-1)  2^(2-1)
// now I have no. of ways to make xor of any position bit zero 
// now what to do ? we want all bit  simultaneously zero 
// multiply then do -1

// 0 1
// 1 0    
// 1 1 -> 2^(1-1) * 2^(1-1)
// chal bsdk ye nahi karenge what I will do is in lower bits

// where r represent how many element to select
// and make it zero 
// if even  -> one's 
// we can do nc0 + nc2 + nc4 + .... ncn
// how many element to select 
// if odd  -> even's
// we can do nc1 + nc3 + nc5 + ----

// 2^(n-1)

// no this does not work like this for considering independtly 


    int xorv = 0;
    for(int i = 0;i < n; i++){
        xorv = xorv^ a[i];
    }
    if(n==1){
        cout << 0 << "\n";
        return ;
    }
    if(xorv == 0){
        cout << 1 << "\n";
        return;
    }

    int count = 0;
    for(int i = 0;i < n; i++){
        if((a[i] ^(xorv)) < a[i]){
            count++;
        }
    }
    cout << count << endl;
    

    
    


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
    