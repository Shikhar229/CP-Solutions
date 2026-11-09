#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    int xorv = 0;
    for(int i = 0;i < n; i++){
        int x;
        cin >> x;
        xorv ^= x;
    }
    if(xorv == 0){
        cout << "second\n";
    }
    else{
        cout << "first\n";
    }

    }
    
}