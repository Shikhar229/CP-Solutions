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
    string s;
    cin >> s;
    ll sum = 0;

    int two = 0;
    int six = 0;
    for(char c : s){
        sum += (c-'0');
        if(c-'0' == 2){
            two++;
        }
        if(c-'0' == 3){
            six++;

        }

    }
    if(sum %9 == 0){
        cout << "YES\n";
        return;
    }
    else{
        if(two== 0 && six == 0){
            cout << "NO\n";
            return;
        }
        else if(two == 0){
            for(int i = 1; i<= six; i++){
                int temp = sum + (6*i);
                if(temp % 9 == 0){
                    cout <<"YES\n";
                    return;
                }
            }
        }
        else if(six == 0){
            
            for(int i = 1; i<= two; i++){
                int temp = sum + 2*i;
                if(temp % 9 == 0){
                    cout << "YES\n";
                    return;

                }


            }
        }
        else{
            // both are there
            sum %= 9;
            for(int i = 0; i <= min(two,8); i++){
                for(int j = 0; j <= min(six,2) ; j++){
                    int temp = sum + 2 * i+  6 * j;
                    if(temp % 9== 0){
                        cout << "YES\n";
                        return;
                    }

                }

            }
            
        }
        cout << "NO\n";

        

    }




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}