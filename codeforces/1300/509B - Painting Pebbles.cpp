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
    int n,k;
    cin >> n>> k;
    vector<int>a(n);

    for(int i  = 0;i < n; i++){
        cin >> a[i];
    }

    int mini = *min_element(a.begin(),a.end());
    int maxi = *max_element(a.begin(),a.end());

    if(maxi-mini <= k){
        // har index me 1 push kar do
        vector<vector<int>>vec(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mini; j++){
                vec[i].push_back(1);

            }
        }

        


        // ab ham 1 to n saare colors daalenge
        for(int i = 0;i < n; i++){
            a[i]-= mini;
        }
        // ab jitna a[i] ka size hai utne number us index par push karne hai
        for(int i = 0;i < n; i++){
            if(a[i] != 0){
                
                for(int j = 1; j <= a[i]; j++){
                    vec[i].push_back(j);
                }
                
                
                
            }
        }

        cout << "YES\n";
        for(int idx = 0;idx < n; idx++){
            for(int j = 0; j < vec[idx].size(); j++){
                cout << vec[idx][j] << " ";
            }
            cout << "\n";


        }

    }
    else{
        cout << "NO\n";
    }
    
    


    


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // int t;
    // cin >> ;

    // while (t--) {
    //     solve();
    // }
    solve();

    return 0;
}