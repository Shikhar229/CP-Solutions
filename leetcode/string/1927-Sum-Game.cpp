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

        if(lq > rq){
            int rem= lq-rq;
            // game will shift to left
            if(rem %2 == 1){
                return true;

            }

            int option = (rem + 1)/2;
            int diff =  rightsum-leftsum;
            if(diff - 9*option !=0){
                return true;
            }
            else{
                return false;
            }

        }
        else if(lq < rq){
            int rem= rq-lq;
            if(rem % 2 == 1){
                return true;
            }

            int option = rem/2;
            int diff = leftsum -rightsum;
            if(diff - 9* option != 0){
                return true;

            }
            else{
                return false;
            }


            

        }
        else{
            if(leftsum == rightsum){
                return false;
            }
            else{
                return true;
            }

        }
        
    }
};