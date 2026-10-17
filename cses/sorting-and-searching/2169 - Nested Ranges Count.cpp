#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long

using namespace std;

using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    int n;
    cin >> n;
    vector<tuple<ll,ll,int>>vec;
    for(int i = 0;i < n; i++){
        ll x,y;
        cin >> x >> y;
        vec.push_back({x,y,i});
    }
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
    if (get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
});

    ordered_set pbds;
    vector<int>contains(n,0);
    for(int i = n-1;i >= 0;i--){
        ll x = get<0>(vec[i]);
        ll y = get<1> (vec[i]);
        int id = get<2>(vec[i]);
        int count = pbds.order_of_key({y+1,LLONG_MAX});
        contains[id] = count;
        pbds.insert({y,i});

    }

    for(int i = 0;i <n;i++){
        cout << contains[i]<< " ";
    }
    cout << "\n";
    vector<int>contained(n,0);
    pbds.clear();
    pbds.insert({get<1>(vec[0]),get<2>(vec[0])});
    for(int i = 1; i < n;i++){
        ll y = get<1>(vec[i]);
        ll id = get<2>(vec[i]);
        int count = pbds.size()-pbds.order_of_key({y,LLONG_MIN});
        contained[id] = count;
        pbds.insert({y,get<2>(vec[i])});
    }
    for(int i = 0;i < n; i++){
        cout << contained[i] << " ";
    }
    

}