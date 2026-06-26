class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    queue<pair<int,int>> q;
            
                ans++;
                q.push({i,j});
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    for(int k=0;k<4;++k){
                        int rr=r+delrow[k];
                        int cc=c+delcol[k];
                        if(rr>=0 && rr<n && cc>=0 && cc<m && grid[rr][cc]=='1'){
                            q.push({rr,cc});
                            grid[rr][cc]='0';
                        }
                    }

                }
            }
        }
        }
        return ans;
        
    }
};