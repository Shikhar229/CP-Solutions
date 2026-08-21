#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>a(n);
        for(int i = 0;i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll bob = 0;
        ll alice = 0;

        bool baari = 0;
        // alice

        for(int i = n-1;i >= 0; i--){
            if(baari == 0){
                if(a[i]%2 == 0){
                    alice += a[i];

                }
                baari = 1;
            }
            else{
                if(a[i]%2 == 1){
                    bob += a[i];

                }
                
                baari = 0;
            }


        }

        if(alice == bob){
            cout << "Tie\n";
        }
        else if(alice > bob){
            cout << "Alice\n";

        }
        else{
            cout << "Bob\n";
        }
    }
}