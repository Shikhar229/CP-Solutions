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

ll ncr(ll n, ll r) {
    if (r > n - r)
        r = n - r;

    ll ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
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



// expected TC : - 
// O(n) or O(m) or O(nlogm) or O(mlogn)




// Observation : - 
void solve() {

    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i = 0; i< n; i++){
        for(int j = 0;j < m ;j++){
            cin >> a[i][j];
        }
    }

    // operation :
    // choose r and c
    // us choosen row aur column ke element ko dec by 1
    // minimum possible maximum value in the matrix a after 
    // performing exactly one operation 

    int maxi = INT_MIN;

    for(int i = 0;i <n;i++){
        for(int j = 0;j < m; j++){
            maxi = max(maxi,a[i][j]);

        }
    }

    int count = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m ;j++){
            if(a[i][j] == maxi) count++;
        }
    }
    // we calculate on each row and column
    vector<int>row(n,0);
    vector<int>col(m,0);

    for(int i = 0;i < n; i++){
        // ith row liya hai
        int cnt = 0;
        for(int j = 0;j < m; j++){
            if(a[i][j] == maxi)cnt++;

        }
        row[i] =cnt;
    }

    for(int j = 0; j < m ; j++){
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i][j] == maxi){
                cnt++;
            }

        }
        col[j] = cnt;
    }

    // for(int i = 0;i < n; i++){
    //     cout <<row[i] << " ";
    // }
    // cout << endl;
    // for(int j =0;j < m ;j++){
    //     cout << col[j] << " ";
    // }
    // cout << endl;


    // har row and column me kitne maximum hai wo stored hai and total kitne maximum  hai wo bhi stored hai mere pass


    // I have counted no. of maxima in the nxm matrix

    int ans = maxi;
    for(int i = 0;i <n ;i++){
        // i take ith row for this row ith row we have to check for all j
        for(int j = 0;j < m; j++){
            // i take ith row and jth column 
            int cal = row[i] + col[j];
            if(a[i][j] == maxi){
                cal--;
            }
            if(cal == count){
                ans = maxi-1;
                break;

            }


        }

    }
    cout << ans << "\n";
    // cout << "next\n";




    

    

}

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