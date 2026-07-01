class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> v(n);
        for(int i=0;i<flights.size();++i){
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            v[from].push_back({to,price});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            auto t=pq.top();
            int stop=t.first;
            int node=t.second.first;
            int cost=t.second.second;
            pq.pop();
            if(stop>k){
                continue;
            }
            for(int i=0;i<v[node].size();++i){
                int adj_node=v[node][i].first;
                int wt=v[node][i].second;
                
                    if(cost+wt<dist[adj_node] && stop<=k){
                        dist[adj_node]=cost+wt;
                        pq.push({stop+1,{adj_node,dist[adj_node]}});
                    }
                
            }

        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};