class Solution {
public:
    bool sumGame(string num) {
        int n= num.size();
        int m = n/2;

        int leftsum = 0;
        int rightsum = 0;

        int lq = 0;
        int rq = 0;
        for(int i = 0;i < n ;i++){

            if(i < m){
                if(isdigit(num[i])){
                    leftsum += num[i]-'0';
                }
                else{
                    lq ++;
                }
            }
            else{
                if(isdigit(num[i])){
                    rightsum += num[i]-'0';

                }
                else{
                    rq ++;
                }
            }
        }

        if((lq+rq) %2 == 1){
            return true;
        }

        return leftsum-rightsum != 9 * (rq-lq)/2;
            
        

        
        
    }
};