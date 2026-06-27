bool dfs(unordered_map<int,vector<int>> &m,vector<int> &vis,vector<int> &path,int node,vector<int> &ans){
    vis[node]=1;
    path[node]=1;
    
    for(int nbr : m[node]){
         if(!vis[nbr]){
            if(!dfs(m,vis,path,nbr,ans)){
                
                return false;
            }
         }else if(path[nbr]){
            
            return false;
         }
    }
    path[node]=0;
    ans.push_back(node);
    return true;
}
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> m;
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> ans;
        for(int i=0;i<p.size();++i){
            int pre=p[i][1];
            int cou=p[i][0];
            m[pre].push_back(cou);
        }
        for(int i=0;i<n;++i){
            if(!vis[i]){
                if(!dfs(m,vis,path,i,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};