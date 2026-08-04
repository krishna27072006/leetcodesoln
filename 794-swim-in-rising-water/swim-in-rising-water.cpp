class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int time=0;
        pq.push({grid[0][0],{0,0}});
        int dc[]={1,0,-1,0};
        int dr[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();

            int ele=t.first;
            int r=t.second.first;
            int c=t.second.second;

            if(vis[r][c]) continue;
            vis[r][c]=1;
            
            time =max(time,ele);
            
            if(r==n-1 && c==n-1){
                break;
            }
            for(int k=0;k<4;++k){
                int rr=r+dr[k];
                int cc=c+dc[k];
                if(rr>=0 && rr<n && cc>=0 && cc<n && vis[rr][cc]!=1){
                    pq.push({grid[rr][cc],{rr,cc}});
                }

            }

        }
        return time;



        
        
    }
};