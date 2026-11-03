class Solution {
public:
    vector<vector<int>>dp;
    int memo(vector<vector<int>>&dp, int i, int j,int m , int n,vector<vector<int>>& grid){
        if(i == m-1 && j ==  n-1){
            dp[i][j] = grid[i][j];
            return dp[i][j];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        // dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i][j+1])

        int right = INT_MAX;
        int down = INT_MAX;
        if(j+1 < n){
            right = memo(dp,i,j+1,m,n,grid);
        }
        if(i+1< m){
            down = memo(dp,i+1,j,m,n,grid);
        }
        dp[i][j] = grid[i][j];
        if(right== down && right == INT_MAX){
            return dp[i][j];
            

        }
        else{
            dp[i][j]+= min(right,down);
            return dp[i][j];

        }
        return -1;


    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<int>(n,INT_MAX));
        memo(dp,0,0,m,n,grid);
        return dp[0][0];
        
    }
};