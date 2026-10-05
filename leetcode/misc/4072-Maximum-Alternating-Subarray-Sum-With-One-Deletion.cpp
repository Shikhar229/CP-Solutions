class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // how to optimize brute force
        // [5,-5,1]
        //In any subarray if the current index is even then negate it 
        // otherwise take + 
        // dp -> to calculate the best prefix
        // dp[i] -> best prefix
        // also there would be j
        // dp[i][j] -> j tells ith element is even or odd
        // deletion can also take place  -> k
        // dp[i][j][k]
        // dp[i][parity][isdeleted]
        // Best prefix such that the last element has parity(parity) & we have used or not used delete

        // if nums[i] -> will be candidate then it may be either + or - 
        // depending on the parity
        // nums[i] + dp[i-1][parity][isdeleted]
        // iteratively or recursively
        // not used dp[i][parity][1] = dp[i-1][parity][isdeleted]
        // Index i tak process karte hue, nums[i] ko chosen subarray ka part maan kar, current parity parity hai aur isDel deletions use hui hain — maximum alternating sum kya hai?

        // del = 1 no deletion
        // del = 0 deletion





         int n = nums.size();
        long long NEG = -1e18;

        vector<vector<vector<long long >>>dp(n,vector<vector<long long>>(2,vector<long long>(2,NEG)));
        long long ans = LLONG_MIN;
        
        for(int i = 0;i < n; i++){
            for(int parity = 0; parity <2 ;parity++){
                for(int del = 0;del < 2 ;del++){

                    // if parity = 0  val = nums[i] 
                    // if parity = 1 val = -nums[i]

                    long long val =  parity== 1? -1LL* nums[i]: nums[i];
                    
                    // we try if we start subarray from this point it is benefit or loss
                    if(parity == 0){
                        dp[i][parity][del] = max(dp[i][parity][del],val);

                    }


                    // we add in existing subarray

                    if(i >0 && dp[i-1][1-parity][del] != NEG){
                        dp[i][parity][del] = max(dp[i][parity][del],dp[i-1][1-parity][del] + val);


                    }

                    if(i >0 && dp[i-1][parity][0] != NEG){
                        dp[i][parity][1] = max(dp[i][parity][1],dp[i-1][parity][0]);
                    }
                    ans = max(ans, dp[i][parity][del]);
                
                }
            }
        }
        return ans;

        





        

        
    }
};