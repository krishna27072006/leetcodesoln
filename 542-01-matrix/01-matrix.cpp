class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;

                }else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;
            q.pop();
            ans[r][c]=step;
            for(int i=0;i<4;++i){
                int cr=r+delrow[i];
                int cc=c+delcol[i];
                if(cr>=0 && cr<n && cc>=0 && cc<m && vis[cr][cc]==0){
                    vis[cr][cc]=1;
                    q.push({{cr,cc},step+1});

                }
            }
            

        }
        return ans;


        
    }
};