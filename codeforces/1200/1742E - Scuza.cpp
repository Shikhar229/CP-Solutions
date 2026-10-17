#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;

ll binpow(ll a, ll b)
{
    ll ans = 1;

    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (ll i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    // mujhe ye pata lag gaya ki har stair ki height kitni hai 
    // agar ham kisi ith inex tak pahuch pa rhaa hu to uske 
    // to saare k >= ai(for all ai from 0 to i) hone chahiye 
    vector<ll>pm(n,0);
    pm[0] = a[0];
    for(int i = 1; i< n;i++){
        pm[i] = max(pm[i-1],a[i]);
    }
    // ye increasing hoga then 


    while (q--)
    {
        ll k;
        cin >> k;
        int l = 0;
        int r = n-1;
        int ans= -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(pm[mid] <= k){
                ans = mid;
                l = mid+1;

            }
            else{
                r =mid-1;
            }

        }
        if(ans != -1){
            cout << prefix[ans] << " ";
        }
        else{
            cout << 0 << " ";
        }


    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}