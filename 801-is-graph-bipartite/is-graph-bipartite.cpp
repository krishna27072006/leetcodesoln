class Solution {
private: 
    bool dfs(int node,int col,vector<int> &v,vector<vector<int>> &graph){
        v[node]=col;
        for(auto t : graph[node]){
            if(v[t]==-1){
                if(dfs(t,!col,v,graph)==false){
                    return false;
                }

            }else if(v[t]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> v(n,-1);
        for(int i=0;i<n;++i){
            if(v[i]==-1){
                if(dfs(i,0,v,graph)==false) return false;
            }
        }
        return true;

        
    }
};