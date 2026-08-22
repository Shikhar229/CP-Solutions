class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int len = 2; len <= n-1; len++){
            
            // for each length find starting point
            // and for each starting find ending point
            // partition that 
            
            // portition for all possible k
            
            for(int i = 1;i + len -1 <= n-1; i++){
                
                int j = i+ len-1;
                dp[i][j] = 1e9;
                
                
                for(int k = i; k < j ; k++){
                    int ops = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j],ops);
                }
            }
        }
        return dp[1][n-1];
        
    }
};