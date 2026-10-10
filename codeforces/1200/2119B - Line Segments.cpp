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
// Observation : 
// when I cannot reach the final position : 
// if starting does not equal to final
// then calculate distance from starting point to keep the points on the slop and move in that direction we can reach the point > final then absolutely we can reach that point if no.. of points > 1
// if starting does not equal to final and no.of distances == 1 then only check we can reach using that or not
// if inital and final then if check some distance take away and some close then these combination can reach to starting or not if not not possible cout << "NO" I think for checking far or near go we apply dp 

void solve() {
    // two points are given 
    // (px,py) and (qx,qy)
    // start from (px,py) and perform n operation 
    // in ith operation choose any point such that distance between the point is ai
    // (qx,qy)-> we want to reach at this point

    int n;
    cin >> n;
    ll px,py,qx,qy;
    cin >> px >> py >> qx >> qy;
    vector<ll>a(n);
    for(int i = 0; i < n ;i++){
        cin>> a[i];
    }

    // join inital and final take all the distances choosing positive direction along that joining if that crosses final position coordinate we may reach final point if the minimum we can reach is 
    ll mini = INT_MAX;
    ll maxi = INT_MIN;
    ll sum = 0;
    for(int i = 0;i <n;i++){
        mini = min(mini,a[i]);
        maxi = max(maxi,a[i]);
        sum += a[i];
    }
    // cout << maxi << " " << sum  << "\n";
    // if s=maximum ke against remaining (sum-maxi) ko minus karde tab bhi agar > 0 hai then we know we cannot compromise maximum
    // maximum - (sum-maxi)  

    if(maxi-(sum-maxi) > 0){
        mini = maxi- (sum-maxi);

    }
    else{
        mini = 0;
    }
    mini = mini*mini;

    ll distance = (px-qx)*(px-qx) + (py-qy)*(py-qy);
    ll maxid = sum * sum;
    // cout << maxid << " " << distance << " " << mini << "\n";
    if(distance <= maxid && mini <= distance){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
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

    // solve();

    return 0;
}