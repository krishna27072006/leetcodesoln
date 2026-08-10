class Solution {
public:
    int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=f(i-1,j,grid,dp);
        int up=f(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+min(left,up);
        

    }
    int minPathSum(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
        int mini=1e5;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid,dp);
         
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0 && j==0){
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int right=1e9;
                int down=1e9;
                if(j>0){
                    right=dp[i][j-1];
                }
                if(i>0){
                    down=dp[i-1][j];
                }
                dp[i][j]=grid[i][j]+min(right,down);

            }
        }
        return dp[m-1][n-1];

        
    }
};