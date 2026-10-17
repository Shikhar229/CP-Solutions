#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<tuple<ll,ll,int>>vec;
    for(int i = 0;i < n ; i++){
        ll x,y;
        cin >> x >>y;
        vec.push_back({x,y,i});
    }
    // x and y dono hai mere pass
    // for each index ithe query I want to tell
    // any range is there which whose
    // right <= i.second && left >= i.first  
    // then I would say it contains
    sort(vec.begin(),vec.end(),[] (auto &a , auto &b){
        if(get<0>(a) != get<0>(b)){
            return get<0>(a) < get<0>(b);
        }
        if(get<1>(a) != get<1>(b)){
            return get<1>(a) > get<1>(b);
        }
        return get<2>(a) < get<2>(b);
        

    });
    // find a pair whose second is < equal or given

    // I have sorted order
    vector<ll>suffix(n,LLONG_MAX);

    vector<ll>contains(n,0);


    for(int i = n-2; i>= 0;i--){
        suffix[i] = min(suffix[i+1],get<1>(vec[i+1]));

    }

  
    for(int i = 0;i < n; i++){
        if(suffix[i] <= get<1>(vec[i])){
            contains[get<2>(vec[i])] = 1;

        }
    }

    

    vector<ll>contained(n,0);
    vector<ll>prefix(n,LLONG_MIN);
    for(int i = 1;i < n; i++){
        prefix[i] = max(prefix[i-1],get<1>(vec[i-1]));
    }

    for(int i = 0;i <n ;i++){
        if(prefix[i] >= get<1>(vec[i])){
            contained[get<2>(vec[i])] = 1;
            
        }
        
    }

    for(int i = 0;i <n ;i++){
        cout <<contains[i] << " ";
    }

    cout <<"\n";
    for(int i = 0;i <n ;i++){
        cout << contained[i] << " ";
    }
    cout << "\n";   






}