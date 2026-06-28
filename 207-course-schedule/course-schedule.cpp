
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> m;

        for(int i=0;i<p.size();++i){
            int pre=p[i][1];
            int cou=p[i][0];
            m[pre].push_back(cou);
        }
        int v=m.size();
        vector<int> indegree(n,0);
        vector<int> topo;
        for(auto t :m){
            for(int i=0;i<t.second.size();++i){
                indegree[t.second[i]]++;
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
            for(int i=0;i<m[node].size();++i){
                indegree[m[node][i]]--;
                if(indegree[m[node][i]]==0){
                    q.push(m[node][i]);
                }
            }
        }
        if(topo.size()==n){
            return true;
        }else{
            return false;
        }


        

        
        
    }
};