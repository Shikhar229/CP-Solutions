class Solution {
  public:
  
    int f(int i, int j, vector<int>&arr,vector<vector<int>>&dp){
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = 1e9;
        
        for(int k = i; k < j; k++){
            int ops = arr[i-1] * arr[k] * arr[j] + f(i,k,arr,dp)+ f(k+1,j,arr,dp);
            mini = min(mini,ops);
            
        }
        return dp[i][j] = mini;
        
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // find most effecient way to multiply
        // the matrixes are
        // 2 x 1
        // 1 x 3
        // 3 x 4
        // least number of mutliplications
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
        
        
        
    }
};