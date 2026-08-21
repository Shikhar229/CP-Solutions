#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b,x,y,n;
        cin >>a >> b >> x >> y >> n;
        // choose always lesser number and decrease it
        
        // agar x bada hai par n kam hai
        // if(a <= b){
        //     // a is lesser
        //     // we will decrease a 

        //     if(a-n < x){
        //         // we will not decrease full n
        //         // only some part of n will be
        //         // we want to take a to x
        //         int ops = a-x;
        //         a = x;

        //         n = n - ops;
        //         if(b-n < y){
        //             int ops = b-y;
        //             b = y;
        //             cout << a *b << "\n";
                    


        //         }
        //         else{
        //             // we can take whole remaining ops
        //             int ops = n;
        //             b = b-n;
        //             cout << a * b << "\n";

        //         }

        //     }
        //     else{
        //         // we can decrease whole n
        //         a = a-n;
        //         cout <<  a * b << endl;

        //     }

            
        // }
        // else{

        //     if(b-n < y){
        //         // we will not decrease full n
        //         // only some part of n will be
        //         // we want to take a to x
        //         int ops = b-y;
        //         b = y;

        //         n = n - ops;
        //         if(a-n < x){
        //             int ops = a-x;
        //             a = x;
        //             cout << a *b << "\n";
                    


        //         }
        //         else{
        //             // we can take whole remaining ops
        //             int ops = n;
        //             a = a-n;
        //             cout << a * b << "\n";

        //         }

        //     }
        //     else{
        //         // we can decrease whole n
        //         b = b-n;
        //         cout <<  a * b << endl;

        //     }

        // }

        // decreasing minimum would fail it


        // decrease a firstly

        ll af = a;
        ll bf = b;
        ll xf = x;
        ll yf = y;
        ll nf = n;

        ll newaf = max(af-nf,xf);

        ll ops1 = af -newaf;
        nf = nf- ops1;

        ll newbf = max(bf-nf,yf);
        ll ops2 = bf- newbf;

        ll c1 = newaf * newbf;
        // decrease b firstly

        ll newb = max(b-n,y);

        ll ops11 = b - newb;
        n = n- ops11;

        ll newa = max(a-n,x);
        ll ops22 = a- newa;

        ll c2 = newa * newb;

        cout << min(c1,c2)<<"\n";

        
    

    }
}