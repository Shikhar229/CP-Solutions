class Solution {
public:
    bool checkDivisibility(int n) {
        int m= n;
        long long sum = 0;
        while(m != 0){
            int ld = m% 10;
            m = m/10;
            sum += ld;
        }
        int prod = 1;
        int k = n;
        while(n != 0){
            int ld = n%10;
            n = n/10;
            prod  *= ld;
        }
        if(k%(sum+ prod) == 0){
            return true;
        }
        return false;

        
    }
};