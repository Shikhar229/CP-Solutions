#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;

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

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto & it: a) cin>> it;

    // n cards

    // ith card have number ai written on it
    // conan starts the game
    // in each turn player choooses a number
    // and remove all card which is < ai
    // and that card
    // point to be noted
    // if there are two same card of the same value
    // we remove one card from that 
    // and remove smaller ones
    // don't remove all card of the same card of the same a[i]
    // if we choosen a[i] ->

    // looses if it cannot make move on his turn
    
    
    // i will find the rightmost numbered range
    map<int,int>mp;
    for(int i = 0;i < n; i++){
        mp[a[i]]++;
    }

    int ans = -1;
    for(auto it: mp){
        if(it.second %2 == 1){
            ans = it.first;
        }

    }

    if(ans  == -1){
        cout << "Agasa\n";
    }
    else{
        cout << "Conan\n";
    }

    

    








}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    

    while (t--) {
        solve();
    }

    return 0;
}