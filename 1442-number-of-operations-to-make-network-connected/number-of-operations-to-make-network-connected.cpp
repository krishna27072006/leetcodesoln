class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& c) {
        int m = c.size();
        if (V - 1 > m) {
            return -1;
        }

        vector<vector<int>> adj(V);
        for (int i = 0; i < m; ++i) {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }

        queue<int> q;
        vector<int> vist(V, 0);
        int iter = 0;

        for (int i = 0; i < V; ++i) {
            if (vist[i] == 0) {
                iter++;
                vist[i] = 1;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto adj_node : adj[node]) {
                        if (!vist[adj_node]) {
                            vist[adj_node] = 1;
                            q.push(adj_node);
                        }
                    }
                }
            }
        }

        return iter - 1;
    }
};