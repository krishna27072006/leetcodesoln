class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int color) {
        if(im[sr][sc] == color)
        return im;
        int n=im.size();
        int m=im[0].size();
        int o=im[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto t =q.front();
            q.pop();
            int i=t.first;
            int j=t.second;
            im[i][j]=color;
            if(i+1<=n-1 && im[i+1][j]==o ){
                im[i+1][j]=color;
                q.push({i+1,j});
            }
            if(i-1>=0 && im[i-1][j]==o ){
                im[i-1][j]=color;
                q.push({i-1,j});
            }
            if(j+1<=m-1 && im[i][j+1]==o ){
                im[i][j+1]=color;
                q.push({i,j+1});
            }
            if(j-1>=0 && im[i][j-1]==o ){
                im[i][j-1]=color;
                q.push({i,j-1});
            }

        }
        return im;
    }
};