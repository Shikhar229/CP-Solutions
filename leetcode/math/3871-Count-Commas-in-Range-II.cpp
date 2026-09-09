class Solution {
public:
    #define ll long long

    long long countCommas(long long n) {
        if(n <= 999){
            return 0;
        }
        ll i = 1;
        ll multiply = 1000;
        ll count = 0;
        while(n >= multiply){
            ll r = min(n, multiply *1000 -1);
            ll curr = (r-multiply +1);

            count += (curr *i);
            i++;
            multiply*= 1000;

        }
        return count;
       
      
    }
};