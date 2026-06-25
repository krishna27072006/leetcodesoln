class Solution {
private:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void dfs(int i,int j, vector<pair<int,int>> &p,vector<vector<int>> &vis,vector<vector<char>> &board){
             
            vis[i][j]=1;
            p.push_back({i,j});
            int n=board.size();
            int m=board[0].size();
            for(int k=0;k<4;++k){
                int ni=i+delrow[k];
                int nj=j+delcol[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0 && board[ni][nj]=='O'){
                    dfs(ni,nj,p,vis,board);

                }
            }

    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> v;
        for(int i=0;i<m;++i){
            if(board[0][i]=='O'){
                v.push_back({0,i});
            }
        }
        for(int i=1;i<n-1;++i){
            if(board[i][0]=='O'){
                v.push_back({i,0});
            }
        }
        for(int i=0;i<m;++i){
            if(board[n-1][i]=='O'){
                v.push_back({n-1,i});
            }
        }
        for(int i=1;i<n-1;++i){
            if(board[i][m-1]=='O'){
                v.push_back({i,m-1});
            }
        }
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        for(int i=0;i<v.size();++i){
            auto t=v[i];
            int r=t.first;
            int c=t.second;
            if(vis[r][c]==0){
                vector<pair<int,int>> p;
                dfs(r,c,p,vis,board);

                for(auto &cell : p)
                {
                    ans[cell.first][cell.second] = 'O';
                }

            }
        }
        board=ans;

        
    }
};