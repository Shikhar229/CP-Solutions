#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int realonel = -1;
    int realoner = -1;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 1){
            if(realonel == -1){
                realonel = i;
            }
            
            realoner = i;
        }
    }
    
    
    if(realonel == -1 && realoner == -1){
        int fakeonel = -1;
        int fakeoner = -1;
        for(int i = 0;i< n ;i++){
            if(a[i] == -1){
                if(fakeonel  == -1){
                    fakeonel = i;

                }
                fakeoner = i;
            }

            
            
            
        }
        
        if(fakeonel == -1){
            // .na 1 hai na -1 ha kuch nahi karna 
            
           
        }
        else{
            
            a[fakeonel] = 1;
            
            a[fakeoner]= 1;
            
        }
        for(int i = 0;i < n; i++){
            if(a[i] == -1){
                a[i] = 0;
            }
            cout << a[i] << " ";
        }
        cout << "\n";
        
        
        
    }
    else{
        for(int i = 0;i < realonel ; i++){
            if(a[i] == -1){
                a[i] = 1;
                break;
            }
        }
        
        for(int i = n-1; i> realoner ; i--){
            if(a[i] == -1){
                a[i] = 1;
                break;
            }
        }
        
        for(int i = 0;i < n; i++){
            if(a[i] == -1){
                a[i] = 0;
            }
            cout << a[i] << " ";
        }
        cout << "\n";
        
    }
    
    

    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}