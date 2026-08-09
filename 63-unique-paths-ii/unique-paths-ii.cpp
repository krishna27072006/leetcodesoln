class Solution {
public:
    int f(int i,int j,vector<vector<int>> & obstacle,vector<vector<int>> &dp){
        if(i==0 && j==0 && obstacle[i][j]!=1){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(obstacle[i][j]==1) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=f(i-1,j,obstacle,dp);
        int left=f(i,j-1,obstacle,dp);
        return dp[i][j]=up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,obstacleGrid,dp);
        
    }
};