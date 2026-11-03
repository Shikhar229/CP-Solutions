class Solution {
public:
    long long inf = 10000000000000000;
    #define ll long long
    vector<ll>dp;

    ll memo(int i, int n, vector<ll>&dp, vector<int>&nums){
        if(i >= n){
            return 0;
            
        }

        if(dp[i] != -inf){
            return dp[i];
        }

        ll pick = nums[i] + memo(i+2,n,dp,nums);
        ll skip = memo(i+1,n,dp,nums);
        return dp[i] = max(pick,skip);

        

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,-inf);
        return memo(0,n,dp,nums);
        
    }
};