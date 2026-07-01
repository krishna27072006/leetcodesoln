class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int S) {
        vector<vector<int>> adj[V+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        vector<int> dist(V+1);
        for(int i=0;i<V+1;++i){
            dist[i]=1e9;
        }
        dist[S]=0;   
        while(!pq.empty()){
            auto t =pq.top();
            int step=t.first;
            int node=t.second;
            pq.pop();
            if(step > dist[node])
                continue;
            for(auto it :adj[node]){
                 int edgeweight=it[1];
                 int adjnode=it[0];
                 if(dist[node]+edgeweight<dist[adjnode]){
                    dist[adjnode]=dist[node]+edgeweight;
                    pq.push({dist[adjnode],adjnode});
                 }
            }
        }
        int maxi = 0;

for(int i = 1; i <= V; i++){
    if(dist[i] == 1e9)
        return -1;
    maxi = max(maxi, dist[i]);
}

return maxi;
        
    }
};