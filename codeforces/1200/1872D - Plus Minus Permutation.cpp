#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd (ll a,ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin>> n >> x >> y;
        // sum of all  pi -> 
        // i divisible by x
        // i divisible by y

        // among all permutation of length n
        // x se divisible highest rakhne hai 
        // to unko to jo higherst hai i ke multiples me rakh do 
        // baaki bache jo honge unko rehne do 
        // and jo y ke multiple hai jo x ke indices se collide nahi kar rahe hai waha 
        // wo number rakhenge jo y se divisible nahi hai 
        
        // vector<int>a(n+1,0);
        // // I made the array for it 
        // // indexes which are divisible by x are marked by 1
        
        // for(int i = 1; i<= n; i++){
        //     if(i % x == 0){
        //         a[i] = 1;
        //     }
            
        // }
        // int countx = 0;
        // for(int i = 1; i<= n; i++){
        //     if(a[i] == 1){
        //         countx++;
        //     }
        // }

        // // I want to take count -> 
        // int usedx = n-countx;
        

        // for(int i = 1; i<= n; i++){
        //     if(a[i] == 0 && i%y == 0){
        //         a[i] = 2;
        //     }
        // }
        // int county = 0;
        // for(int i = 1; i<= n; i++){
        //     if(a[i]== 2){
        //         county++;
        //     }

        // }
        // int usedy = county;
        // ll sum = usedy* (usedy+1)/2;

        // ll sum2 = 0;
        // for(int i = usedx+1 ; i <= n; i++){
        //     sum2 += i;
            
        // }
        // cout << sum2-sum << "\n";

        // I just want how many number divisible by x
        // and I want how many number divisible by y
        // n/x divisible by x
        // sum of these 


        // how many indices are divisible by x

        // indices which are divisible by both number
        // if I put anything that on that indices it simply will be discarded
        // then put the lowest ones so it discarded don't harm anything specific

        ll both = n/lcm(x,y);
        
        ll onlyx = (n/x)- both;
        
        ll onlyy = (n/y)-both;
        // cout << onlyx << " " << onlyy << "\n";

        ll sumx = ((onlyx)*(2*n + 1 - onlyx))/2;
        
        ll sumy = ((onlyy)*(onlyy+1))/2;
        // cout << sumx << " " << sumy << "\n";

        cout << sumx-sumy << "\n";



    }
    
}