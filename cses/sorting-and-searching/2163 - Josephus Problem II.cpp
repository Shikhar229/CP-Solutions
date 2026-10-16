#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
using namespace __gnu_pbds;
 
 
using ordered_set = tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 

 
int main(){
    int n,k;
    cin >> n >> k;
    ordered_set nums;
    for(int i = 1;i <= n;i++){
        nums.insert(i);
    }
 
    int pos = 0;
    while(!nums.empty()){
        pos = (pos + k)% nums.size();
        auto it = nums.find_by_order(pos);
        cout << *it << " ";
        nums.erase(it);
    }
 
 
    
}