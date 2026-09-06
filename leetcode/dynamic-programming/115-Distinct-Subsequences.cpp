class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j , string s, string t,vector<vector<int>>& dp){

        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return  dp[i][j] = solve(i+1, j+1, s,t,dp) + solve(i+1, j ,s,t,dp);
            
        }
        return dp[i][j] = solve(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = solve(0,0,s,t,dp);
        return ans;
        
    }
};