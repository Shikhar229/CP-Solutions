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
bool isPrime(ll n) {
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
// O(n) or O(nlogn)




// O(n) or O(nlogn) ->     think of-> sorting
                                // ->monotonocity(binary search)
                                // ->priority queue

// Binary search on Answer sometimes think of current maxima and second maxima
// --------------------------/



// Observation : 





// -----solve-----
void solve() {
    // /n planks 
    // k color
    // planks of same color
    // one plank can be repainted

    int n,k;
    cin >> n >>k;
    // no. of planks in bridge ->n
    // no. of different colors of paint ->k
    // har color ki posititon nikal lete hai and binary search on answer on each color ki kisme paint kiya jaye 
    // for a color c[i] lets say uski position kuch i1 , i2 ,i3 ,.....
    // hai then usme jo sabse bada gap hoga uske left position and right position se binary search on position karnege ki kaha color kare we color and store some where for that color c[i]-> maximum distance after repaining some we do for each color 

    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    vector<vector<int>>vec(k+1);
    for(int i = 0;i< n; i++){
        int x = a[i];
        
        vec[x].push_back(i+1);

    }



    // har position par jao us color ki last postion
    //  se current color ki distnace nikalo 
    // if current color ki distnace is larger than
    // maximum gap of that color 
    // then update maximum gap 
    // and updatre second maximum to previouse maximum
    // if the gap is smaller than second maximum do nothing to update
    // just update positon of color 
    // if gap > second gap then update second maximum 

    // at the end I will have maxima and second maxima for each color then we only need to calculate max(maxima/2 , second  maxima) for each color take maxima of all
    
    // for each color startingly put last postion and after calculating maxima and secon maxima for each color iterate a extra loop to have diffeerence between last position and that color last position
    
    // I set last position of each color to 0

    // now I will find maxima and second maxima for each color
    // before that I will set INT_MIN

    vector<int>last(k+1,0);

    vector<int>mx(k+1,0);
    vector<int>sm(k+1,0);

    for(int i = 0;i < n; i++){
        int idx = a[i];
        int diff  = (i+1) - last[idx]  - 1;

        last[idx] = i+1;

        if(mx[idx] < diff){
            sm[idx] = mx[idx];
            mx[idx] = diff;

        }
        else if(diff > sm[idx]){
            sm[idx] = diff;
        }
        
  
    }
    for(int idx = 1; idx <= k ;idx++){
        int diff = (n)-last[idx];

        if(mx[idx] < diff){
            sm[idx] = mx[idx];
            mx[idx] = diff;

        }
        else if(diff > sm[idx]){
            sm[idx] = diff;
        }
        
        
    }

    // for(int i = 1; i <= k ;i++){
    //     cout << mx[i] << " " << sm[i] << "\n";
    // }
    // cout << "\n\n";

    int mini = n+2;
    for(int i = 1; i<= k ;i++){
        if(vec[i].empty())continue;
        int curr = max(mx[i]/2, sm[i]);
        mini = min(mini,curr);
    }
    cout << mini<< "\n";
  
 

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