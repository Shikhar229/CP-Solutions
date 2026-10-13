#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void dfs(int val , vector<vector<int>>&vec,vector<int>&count){
    // I will go to index no. val
    for(int x : vec[val]){
        dfs(x,vec,count);
        count[val] += (1 + count[x]);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int>a(n-1);
    vector<vector<int>>vec(n+1);
    for(int i = 0;i < n-1; i++){
        cin >> a[i];
        vec[a[i]].push_back(i+2);
        // mp[a[i]].push_back(i+1);
    }
    // for(int  i = 1;i <=n; i++){
    //     cout <<i << "  ";
    //     vector<int>b = vec[i];
    //     for(int j = 0;j < b.size(); j++){
    //         cout << b[j] << " ";

    //     }
    //     cout << "\n";
    // }
    vector<int>count(n+1,0);

    dfs(1,vec,count);

    // Do dfs for each node

    // for(int i = 1; i<= n; i++){
    //     // i reached index i = 1
    //     // traverse jab take vec[curr].empty() na ho jaye 
    //     // call dfs for each 
    //     int c = dfs(i,vec);
    //     count[i] = c;

    // }

    // It taking much time do dfs one's 
    for(int i = 1; i<= n; i++){
        cout << count[i] << " ";
    }


}