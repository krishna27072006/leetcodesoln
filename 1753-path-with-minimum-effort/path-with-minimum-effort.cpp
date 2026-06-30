class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(d > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int rr = r + delRow[i];
                int cc = c + delCol[i];
                if(rr>=0 && rr<n && cc>=0 && cc<m ){
                    int newEffort = max(d, abs(heights[r][c]-heights[rr][cc]));

            if(dist[rr][cc] > newEffort){
                dist[rr][cc] = newEffort;
                pq.push({newEffort,{rr,cc}});
            }
                }
            }

        }
        return dist[n-1][m-1];
        
    }
};