#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // collecting numbers II
    // agar mai 2 and 3 ko swap kar du
    // then kitne 
    int n,m;
    cin >> n >> m;
    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    vector<int>a(n);
    for(int i = 0;i <n ;i++){
        cin >> a[i];
    }
    vector<int>pos(n+1);
    for(int i = 0;i <n ;i++){
        int x = a[i];
        pos[x] = i+1;
    }
    
    // position store ho gayi ab kya karna hai 
    int count = 1;
    for(int i= 1;i < n; i++){
        if(pos[i] > pos[i+1])count++;
    }
    // cout << count << "\n";
    
    // I found the numbers of rounds it would take if it is normal case
    // If I have given swapping numbers
    // then it get swapped
    // we found numbers by pos[x] and pos[y] 
    // if we swap those what will change in answer 
    
    
    while(m--){
        int l,r;
        cin >> l>> r;
        int curr = count;
        l--;
        r--;
        if(l == r) {
            cout << count << "\n";
            continue;
        }
        int x = a[l];
        int y = a[r];
     
        set<pair<int,int>>p;
        if(x-1 >=1) p.insert({x-1,x});
        if(x+1 <= n ) p.insert({x,x+1});
        if(y-1 >=1 ) p.insert({y-1,y});
        if(y+1 <= n)p.insert({y,y+1});
        for(auto z : p){
            if(pos[z.first] > pos[z.second])count--;
        }
        swap(a[l],a[r]);
        pos[x] = r+1;
        pos[y]= l+1;
        
        for(auto z : p){
            if(pos[z.first] > pos[z.second]){
                count++;
            }
            
        }
        cout << count << "\n";
    }
    
    
    
    
}