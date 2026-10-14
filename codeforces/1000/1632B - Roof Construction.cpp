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
    // n pillars.
    // height of pillar is permutation from 0 to n-1
    // pi -> height of ith pillar
    // maximum value of the bitwise xor of heights of all pairs of adjacent pillars
    // cost of construction 

    // I want to arrange pillar such that smallest construction 
    // construction cost -> maximum value of the adjacent xor
    
    // I want to minimize the maximum 
    // jo maximum hai use ek dum last me rakh dunga taaki wo kisi se xor hi na ho aur usme bit hi na badhe 
    

    int n;
    cin >> n;
    // 0 - 000 
    // 1 - 001
    // 2 - 010
    // 3 - 011
    // 4 - 100
    // 5 - 101
    // 6 - 110
    // 7 - 111
    // 8 -1000
    // 9 -1001
   
    // 0 8 11 
    //ab 9 ko ekdum last me rakhenge to aisa to hoga hi ki 
    // jinki highest set bit me 1 hai 1 number aisa bachega hi 
    // jiski highest set bit cancel na ho jiski set bit cancel na ho usko minimum kar du yaani 0 to highest set bit wala minimum number 


    // 8 ke right side me to jiske highest set bit me 1 hai wahi rehna chahiye
    // 8 ke side me 9
    // 9 ke side me  jo cancel kar de wo rakhunga jo left most cancel and if possible right most bhi but ek new bit 1 aa jayega to incr
    // let's say 1011 rakh diya to banega 0010 
    // but 1011 ko cancel karne ke liye 

    // taking n = 8
    // 0 to 7
    // 0 ke side me 4 ok
    // 4 ke side me jo bhi aayega wo apna left most set bit har give up karega
    // 5 ko 4 ke left me kyuki 1 different hai lowest waali
    // 5 ke side me 6 

    // it means jo sabse kam difference walik rakhni lowesgt bit  me 
    // 0 ke left me chahe mai kisi bhi order me rakhu usme highest set bit include nahi hoga to wo chhota hi rakhega 0 xor 4 se 

    int num = 1;
    while(num*2 < n){
        num *= 2;
    }
    for(int i = 1; i <= num-1; i++){
        cout << i << " ";
    }
    cout << 0 << " ";
    for(int i = num; i <= n-1; i++){
        cout << i <<" ";
    }
    cout << "\n";
    

    


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