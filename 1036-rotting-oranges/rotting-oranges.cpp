class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<g.size();++i){
            for(int j=0;j<g[0].size();++j){
                if(g[i][j]==2){
                    q.push({i,j});
                }else if(g[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=0;
        while(!q.empty() && fresh>0){
           ans++;
           vector<pair<int,int>> v;
           while(!q.empty()){
             auto t = q.front();
            q.pop();
            int i=t.first;
            int j=t.second;
            if(i+1<=n-1 && g[i+1][j]==1){
                v.push_back({i+1,j});
                g[i+1][j]=2;
                fresh--;
            } if(i-1>=0 && g[i-1][j]==1){
                v.push_back({i-1,j});
                g[i-1][j]=2;
                fresh--;

            } if(j+1<=m-1 && g[i][j+1]==1){
                v.push_back({i,j+1});
                g[i][j+1]=2;
                fresh--;
            } if(j-1>=0 && g[i][j-1]==1){
                v.push_back({i,j-1});
                g[i][j-1]=2;
                fresh--;
            }
           }
           for(auto t : v){
                q.push(t);
            }

        }
        return fresh==0 ? ans : -1;
        
    }
};