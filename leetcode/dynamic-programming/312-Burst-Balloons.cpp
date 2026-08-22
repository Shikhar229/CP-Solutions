class Solution {
public:
    int f(int i, int j , vector<int>&nums,vector<vector<int>>&dp){
        if(i == j+1) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxi = 0;

        for(int k = i+1;k < j; k++){
            int x = nums[i]*nums[k]*nums[j]+ f(i,k,nums,dp)+f(k,j,nums,dp);
            maxi  = max(maxi,x);
            
            
        }
        return dp[i][j] = maxi;

    }

    int maxCoins(vector<int>& nums) {
        
        int n= nums.size();
        vector<int>arr;
        arr.push_back(1);
        
        for(int i = 0; i < n; i++){
            arr.push_back(nums[i]);

        }
        arr.push_back(1);
        int m= arr.size();
        // we should not sort the array order is important
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(0,m-1,arr,dp);
        
    }
};