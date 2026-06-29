class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> topo;
        vector<vector<int>> g(n);
        for(int i=0;i<graph.size();++i){
            for(int j=0;j<graph[i].size();++j){
                g[graph[i][j]].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<g.size();++i){
            for(int j=0;j<g[i].size();++j){
                indegree[g[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(int i=0;i<g[node].size();++i){
                indegree[g[node][i]]--;
                if(indegree[g[node][i]]==0){
                    q.push(g[node][i]);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;



        
    }
};