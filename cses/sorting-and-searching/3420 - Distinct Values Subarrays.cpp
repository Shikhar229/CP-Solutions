#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    
    // if all elements are distinct then 
    // whenver we find a number a[i] -> then 
    // push_back to every available vector and create also a[i]
    // TC- O(n^2)

    // Brute force not working 
    // find no. of valid subarray ending at index j
    // j -> j+1
    // smallest i such that all numbers are unique

    // Expand window from right one by one
    // shrink the iwndow from left 
    // total += j-i+1

    // 1 2 1 3 2 7 4 2
    // to represent a window I will use map
    // 1 2 2 3 3 4 5 
    
    int left = 0;
    ll ans = 0;
    map<int,int>mp;

    for(int j = 0; j < n ;j++){
        mp[a[j]]++;
        while(mp[a[j]] > 1){
            mp[a[left]]--;
            if(mp[a[left]] == 0){
                mp.erase(a[left]);
            }

            left++;

        }
        ans += mp.size();

    }
    cout << ans << "\n"; 


}