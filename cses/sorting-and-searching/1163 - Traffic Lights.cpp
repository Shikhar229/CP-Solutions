#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){
    ll x,n;
    cin >> x >> n;
    vector<ll>p(n);
    for(int i = 0;i < n; i++){
        cin >> p[i];
    }
    // I want dynamically a position left and right boundary
    // I want to find a number which is just just smaller than x
    // and I want a number which is just greater than that number

    // lower bound >= x
    set<ll>position;
    multiset<ll>length;
    position.insert(0);
    position.insert(x);

    length.insert(x);
    
    for(int i = 0;i < n; i++){
        int q = p[i];
        auto right = position.upper_bound(q);
        auto left = prev(right);

        ll old = *right-*left;
        length.erase(length.find(old));
        length.insert(q-*left);
        length.insert(*right-q);
        position.insert(q);
        
        cout << *length.rbegin()<< " ";
    }
    cout << "\n";


}