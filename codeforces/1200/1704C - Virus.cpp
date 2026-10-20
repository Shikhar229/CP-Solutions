#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<ll> gap;

        for (int i = 0; i < m - 1; i++)
        {
            ll x =  a[i + 1] - a[i]-1;
            gap.push_back(x);
        }
        ll last = n - (a.back() - a[0]) - 1;


        gap.push_back(last);

        sort(gap.begin(), gap.end());

        

        // I have all sorted gap length now I will start from end
        ll ans = 0;
        int x = gap.size();

        // for(int i = 0;i <x;i++){
        //     cout << gap[i] << " ";
        // }
        // cout << "\n";
        ll start = 0;

        
        for (int i = x - 1; i >= 0; i--)
        {

            // ll reduced = gap[i] - 4* start;
            ll current = gap[i] - 2* start;
            if(current <= 0)break;
            if(current == 1){
                start += 1;
                ans++;
                
            }
            else{
                start += 2;
                ans += (current - 1);
            } 
                
        }
        cout << n-ans << "\n";
        // cout << "\n";
    }
}