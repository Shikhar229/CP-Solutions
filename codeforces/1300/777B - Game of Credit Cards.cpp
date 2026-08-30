#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string c,d;
    cin >> c >> d;
    
    vector<int>a(n),b(n);
    for(int i = 0;i < n; i++){
        a[i] = c[i]-'0';
        b[i] = d[i]-'0';
        
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // I want minimum then I want ki ith position par
    // mujhe uske a[i] ke barabar b[i] mil jaye ya a[i] se bada koi ho to
    // agar na hi mujhe barabar mila aur na hi bada to us index se leke last index to jitne numbers hai wo sab count honge



    // I want to maximize schol count 

    map<int,int>mp;
    map<int,int>m;
    for(int x: b){
        mp[x]++;
        m[x]++;
    }
    int i;
    for(i = 0;i < n; i++){
        int x = a[i];
        auto itx = mp.find(x);
        if(itx != mp.end()){
            itx->second--;
            if(itx->second == 0){
                mp.erase(itx);
            }

        }
        else{
            auto it = mp.upper_bound(x);
            if(it != mp.end()){
                it->second--;
                if(it->second == 0) mp.erase(it);
            }
            else{
                break;
            }
        }

    }
    cout << n-i<< "\n";


    int count2 = 0;
    int j;
    for(j = 0;j < n; j++){
        auto it = m.upper_bound(a[j]);
        if(it != m.end()){
            it->second--;
            if(it->second == 0) m.erase(it);
            count2++;
        }
        else{
            break;
        }

    }
    cout << count2 <<"\n";
    

}