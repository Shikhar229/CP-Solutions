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
        string s;
        cin >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<ll> r(n);
        for (int i = 0; i < n; i++)
        {
            ll sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
            r[i] = sum;
        }

        vector<ll> c(m);
        for (int j = 0; j < m; j++)
        {
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i][j];
            }
            c[j] = sum;
        }
        ll x = 0;
        ll y = 0;

        ll idx = 0;
        while (idx < s.size())
        {

            if (s[idx] == 'D')
            {
                a[x][y] = -r[x];
                r[x] += a[x][y];
                c[y] += a[x][y];
                x++;
            }
            else
            {
                a[x][y] = -c[y];
                r[x] += a[x][y];
                c[y] += a[x][y];
                y++;
            }
            idx++;
        }
        // len of string 3 then
        // move honge length of string ke aur last box reh jayega to last box alaga se bhar dunga
        a[x][y] = -r[x];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}