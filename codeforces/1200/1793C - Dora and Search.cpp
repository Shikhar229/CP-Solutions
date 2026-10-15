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

// numbers of l and r (1 <= l <= r <= n)
// al != min(al,al+1,.....,ar)
// ar != min(al,al+1, ......,ar)
// al != max(al,al+1,.......ar)
// ar != max(al,al+1,.......ar)

// al , ar should not be minimum or maximum element 
// it should be between 
// I have permutation 
// maximum suffix bana lu and ek minimum 
// 3 3 3
// 1 2 3

// 4 4 4 3
// 1 1 3 3
// 1 and 4

// build max suffix and min suffix
// iterate over it 
// this will take O(n^3)
// we have to do in O(n) or O(nlogn)
// matlab jo ends point honge wo maximum ya minimum nahi honge 
// beech wale point honge 

// store indexes with values 
// 2 1 4 3

void solve() {

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        
    }
    vector<pair<int,int>>vec;
    for(int i = 0;i <n; i++){
        vec.push_back({a[i],i});
    }

    sort(vec.begin(),vec.end());
    int l = 0;
    int r = n-1;
    int i = 0;
    int j = n-1;

    bool found = false;
    while(i <= j){
        if(a[l] == vec[i].first){
            l++;
            i++;
        }
        else if(a[l] == vec[j].first){
            l++;
            j--;

        }
        else if(a[r] == vec[i].first){
            r--;
            i++;
        }
        else if(a[r] == vec[j].first){
            // highest ke equal
            r--;
            j--;
        }
        else{
            cout << l+1 << " " << r + 1 <<"\n";
            found = true;
            break;
        }
        
        

    }
    if(!found){
        cout << -1 << "\n";
    }
    // cout << "\n";







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
