#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n != 0){
        vector<int>vec(3);
        int count = 0;
        for(int i = 0;i < 3; i++){
            cin >> vec[i];
            if(vec[i]){
                count++;
            }
        }
        
        if(count  >=2){
            ans++;
        }
        n--;
    }
    cout << ans << endl;
}