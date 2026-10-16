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


void josephus_1(vector<int>&nums){
    int n= nums.size();
    if(n == 1){
        cout << nums[0] << "\n";
        return;
    }
    for(int i = 1; i< n;i+=2){
        cout << nums[i] << "\n";

    }
    vector<int>narr;
    if(n%2 == 0){
        for(int i = 0;i <n;i+=2){
            narr.push_back(nums[i]);
        }
    }
    else{
        narr.push_back(nums[n-1]);
        for(int i = 0;i < n-1; i+=2){
            narr.push_back(nums[i]);
        }

    }

    // solve for remaining elements
    josephus_1(narr);


}


void solve()
{

    int n;
    cin >> n;
    vector<int>a(n);


    for (int i = 0; i < n; i ++)
    {
        a[i] = i+1;




    }
    josephus_1(a);




}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}