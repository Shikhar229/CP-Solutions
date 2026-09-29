#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>>vec;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        vec.push_back({b,a});
    }

    sort(vec.begin(),vec.end());
    int prev_end = vec[0].first;

    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(vec[i].second >= prev_end){
            cnt++;
            prev_end = vec[i].first;
        }
    
    }
    cout << cnt << "\n";


}