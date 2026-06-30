class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            auto t =q.front();
            int r=t.first;
            int c=t.second;
            q.pop();
            int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for (int i = 0; i < 8; i++) {
                 int rr = r + delRow[i];
                 int cc = c + delCol[i];
                 if(rr>=0 && rr<n && cc>=0 && cc<n && grid[rr][cc]==0){
                    if(dist[r][c]+1<dist[rr][cc]){
                        dist[rr][cc]=dist[r][c]+1;
                        q.push({rr,cc});
                    }
                    
                 }
            }

        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];


        
    }
};