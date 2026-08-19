class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // n rows of seats
        // each row has 10 seats
        // numbered from 1 to 10
        
        // reservedSeats
        // reservedSeats[i] = [rowi, seati] -> it is reserved
        // four person ka group must be assigned to four seats in the same row

        // agar kisi row ka 4 ya 5 position bhara hai to wo definitely do nahi de sakta 

        // reservedSeats par iterate karenge
        // ha to maximum  query let's say by constraints hogi 10^4
        // then ok har query me gaye
        sort(reservedSeats.begin(), reservedSeats.end());
        int m= reservedSeats.size();

        int count = 0;
        int i= 0;

        int occupy = 0;
        while(i < m){
            int current_row = reservedSeats[i][0];
            occupy++;

            bool left = false;
            bool mid = false;
            bool right = false;

            while(i < m && reservedSeats[i][0] == current_row){
                if(reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5){
                    left = true;

                }
                if(reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 7){
                    mid = true;
                }
                if(reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9){
                    right = true;
                }
                
                
                i++;


            }
            if(left == false && right == false){
                count+= 2;
            }
            else if(left == false || mid == false || right == false){
                count+= 1;
            }
            

        }
       
        return count + ((n-occupy)*2);

        






        



        
    }
};