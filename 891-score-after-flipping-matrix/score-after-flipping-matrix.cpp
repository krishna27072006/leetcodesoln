class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i){
            if(grid[i][0]==0){
                for(int j=0;j<grid[0].size();++j){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }

                }
            }
        }
        for(int i=0;i<grid[0].size();++i){
            int one=0;
            int zero=0;
            for(int j=0;j<grid.size();++j){
                if(grid[j][i]==1){
                    one++;
                }else{
                    zero++;
                }
            }
            if(zero>one){
                for(int j=0;j<grid.size();++j){
                if(grid[j][i]==1){
                    grid[j][i]=0;
                }else{
                    grid[j][i]=1;
                }
            }

            }

        }
        int score = 0;
        for(int i=0;i<grid.size();++i){
            int val = 0;
            for(int j=0;j<grid[0].size();++j){
                val = (val << 1) | grid[i][j];
            }
            score += val;
        }
        return score;
        
    }
};