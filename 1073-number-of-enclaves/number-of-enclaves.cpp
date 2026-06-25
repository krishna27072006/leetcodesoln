class Solution {
    private:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& grid,int &sum)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j]=0;

        sum++;          // Mark as safe

        for(int k = 0; k < 4; k++)
        {
            int ni = i + delrow[k];
            int nj = j + delcol[k];

            if(ni >= 0 && ni < n &&
               nj >= 0 && nj < m &&
               grid[ni][nj] == 1)
            {
                dfs(ni, nj, grid,sum);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        int sum=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j] == 1)
                dfs(0, j, grid,sum);
        }

        // Last row
        for(int j = 0; j < m; j++)
        {
            if(grid[n-1][j] ==1)
                dfs(n-1, j, grid,sum);
        }

        // First column
        for(int i = 1; i < n-1; i++)
        {
            if(grid[i][0] == 1)
                dfs(i, 0, grid,sum);
        }

        // Last column
        for(int i = 1; i < n-1; i++)
        {
            if(grid[i][m-1] == 1)
                dfs(i, m-1, grid,sum);
        }
        return total-sum;
    }
};