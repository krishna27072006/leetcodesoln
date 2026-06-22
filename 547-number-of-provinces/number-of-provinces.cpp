class Solution {
public:
    void dfs(int i,vector<vector<int>> &isConnected,vector<int> &v){
        v[i]=1;
        for(int j=0;j<isConnected[i].size();++j){
            if(isConnected[i][j] && !v[j]){
                dfs(j,isConnected,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<int> v(n,0);
        for(int i=0;i<n;++i){
            if(v[i]!=1){
                dfs(i,isConnected,v);
                ans++;

            }
        }
        return ans;
    }
};