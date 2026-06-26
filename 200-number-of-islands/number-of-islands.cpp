class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    v.push_back({i,j});
                }
            }
        }
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int ans=0;
        vector<vector<char>> vis(n,vector<char>(m,'0'));
        for(int i=0;i<v.size();++i){
            int l=v[i].first;
            int k=v[i].second;
            queue<pair<int,int>> q;
            if(vis[l][k]=='0'){
                ans++;
                vis[l][k]='1';
                q.push({l,k});
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    for(int i=0;i<4;++i){
                        int rr=r+delrow[i];
                        int cc=c+delcol[i];
                        if(rr>=0 && rr<n && cc>=0 && cc<m && vis[rr][cc]=='0' && grid[rr][cc]=='1'){
                            q.push({rr,cc});
                            vis[rr][cc]='1';
                        }
                    }

                }


            }
        }
        return ans;
        
        
    }
};