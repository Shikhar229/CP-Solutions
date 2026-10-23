#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        bool found = false;
        for(int i= 0;i < n; i++){
            if(s[i] != c){
                found = true;
                break;
            }
        }

        if(!found){
            cout << 0 << "\n";

        }
        else{
            // exactly 1 rehne ke liye 
            // go from x -> [1,n]
            bool g = false;
            int p = -1;

            for(int x = 1; x <= n; x++){
                bool found = false;
                for(int i= x; i <= n; i+=x){
                    int idx = i-1;
                    if(s[idx] != c){
                        found = true;
                        break;
                    }

                }
                if(!found){
                    // agar mil gaya us x ke multiple par
                    // koi na koi c to wo change nahi hoga
                    // yaha par mujhe c nahi mila
                    // kis bhi multiple par then kya karunga
                    g = true;
                    p = x;
                    break;


                }
                else{
                    // I will continue to find another x 
                    continue;
                    // agar koi bhi x nahi mila jiska multiple 
                    // satisfy kare condition ko then output 
                    // karenge 2
                }
            }  
            if(g) {
                cout <<1 << "\n";
                cout << p << "\n";
            } 
            else{
                cout << 2 << "\n";
                cout << n << " " << n-1 << "\n";
            }
            
        }
    }
}