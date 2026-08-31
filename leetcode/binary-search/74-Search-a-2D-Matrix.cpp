class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        int low = 0;
        int high = n*m-1;

        bool found = false;


        while(low <= high){
            int mid = low + (high-low)/2;
            int value = matrix[mid/n][mid% n];
            if(value == target){
                
                return true;

            }
            else if(value < target){
                low = mid+1;

            }
            else{
                high = mid-1;
            }

        }
        return false;
       
        
    }
};