class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int mod = 1e9+7;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto t : adj[node]){
                int adj_node=t.first;
                int wt=t.second;

                if(dis+wt < dist[adj_node]){
                    dist[adj_node]=dis+wt;
                    pq.push({dist[adj_node],adj_node});
                    ways[adj_node]=ways[node];
                }
                else if(dis+wt == dist[adj_node]){
                    ways[adj_node]=(ways[adj_node]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};