#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long

using namespace std;
using namespace __gnu_pbds;



using ordered_set = tree<
    tuple<ll,ll,int>,
    null_type,
    less<tuple<ll,ll,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// st.order_of_key(x)
// how many elements are strictly less than x
// find_by_order(k) ->this give index k par kon sa element hai uska order


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
    vector<tuple<ll,ll,int>>vec;
    for(int i = 0;i < n; i++){
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y,i});
    }
    sort(vec.begin(),vec.end());
    ordered_set st;

    int room = 1;
    vector<int>ans(n);
    for(int i= 0;i <n;i++){
        ll x = get<0>(vec[i]);
        ll y = get<1>(vec[i]);
        ll idx = get<2>(vec[i]);

        // how many element s are less then
        // x


        if(!st.empty() && get<0>(*st.begin()) < x ){
            auto it = st.begin();
            ll ro = get<1>(*it);
            st.erase(it);
            st.insert({y,ro,idx});
            ans[idx] = ro;
            
        }
        else{
            // agar mujhe nahi mila to 
            ans[idx] = room;
            st.insert({y,room,idx});
            room++;
            
        }


    }
    cout << room-1 << "\n";
    for(int i= 0;i < n ;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";



    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 
    solve();

    return 0;
}