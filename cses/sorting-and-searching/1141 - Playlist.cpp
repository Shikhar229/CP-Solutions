#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i= 0;i <n; i++){
        cin >> a[i];
    }
    // choose tow indexes count how many uniques are there store it 
    
    unsigned ll maxi = 0;
    int l = 0;
    set<ll>st;
    for(int r = 0;r < n;r++){
        while(st.count(a[r])){
            st.erase(a[l]);
            l++;
        }

        st.insert(a[r]);
        maxi = max(maxi,1LL* st.size());
    }
    cout << maxi << "\n";
    
    
    
    
}