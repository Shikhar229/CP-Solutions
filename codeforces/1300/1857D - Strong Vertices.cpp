#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<ll> a(n ), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        // edge from u to v exist if
        // au-av >= bu- bv

        // au- bu >= av - bv
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i].first = a[i] - b[i];
            temp[i].second = i;
        }
        // for(int i = 0;i < n; i++){
        //     cout << temp[i].first <<" ";
        // }
        // cout << endl;

        // agar koi aisa index mil gaya to dekho
        // tell how many strong vertexes are there
        // [-1, -2, 0, 3]
        // [-4,0,1,-2,1]

        // sort the array
        // tell the index where it is same from last index
        sort(temp.begin(), temp.end());
        int last = temp[n - 1].first;
        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp[i].first == last)
            {
                idx = i;
                
            }
            else
            {
                break;
            }
        }
        cout << n-idx << endl;
        for (int i = idx; i < n; i++)
        {
            cout << temp[i].second+1 <<" ";
        }
        cout << "\n";
    }
}