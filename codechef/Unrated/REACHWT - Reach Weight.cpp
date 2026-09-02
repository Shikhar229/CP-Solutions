#include <bits/stdc++.h>

using namespace std;

int main() {
        // your code goes here
        int t;
        cin >> t;
        while (t--) {

            int n;
            cin >> n;
            if (n % 2 == 0) {

                int x = (n / 2) * 30;
                cout << x << endl;

            }
            else {
                int x = n/2;
                int cost = x* 30  + 20;
                cout << cost << endl;


            }
        }
}