class Solution {
public:

    vector<vector<int>>dp;

    int memo(int m , int n , int i, int j, vector<vector<int>>&dp, vector<vector<int>>& grid){
        if(i == 0 && j == 0){
            return dp[0][0] = grid[0][0];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int top = INT_MAX;
        int left = INT_MAX;

        if(i-1 >= 0){
            top = memo(m,n,i-1,j,dp,grid);
        }

        if(j-1>= 0){
            left = memo(m,n,i,j-1,dp,grid);


        }
        dp[i][j] = grid[i][j];

        if(top == left && top != INT_MAX || top != left){
            dp[i][j] += min(top,left);
        }
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        dp.assign(m, vector<int>(n,INT_MAX));
        memo(m,n,m-1,n-1,dp,grid);
        return dp[m-1][n-1];
        
    }
};