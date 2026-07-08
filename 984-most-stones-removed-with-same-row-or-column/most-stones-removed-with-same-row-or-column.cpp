class Disjointset{
    vector<int> rank,parent,size;
    public:
    Disjointset(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void unionByRank(int v,int u){
        int ulp_v=findUpar(v);
        int ulp_u=findUpar(u);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }

    }
    void unionBySize(int v,int u){
        int ulp_v=findUpar(v);
        int ulp_u=findUpar(u);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it : stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);

        }
        unordered_map<int,int> uniques;

        Disjointset ds(maxrow+maxcol+1);
        for(auto it : stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBySize(noderow,nodecol);
            uniques[noderow]=1;
            uniques[nodecol]=1;

        }
        int ct=0;
        for(auto it : uniques){
            if(ds.findUpar(it.first)==it.first){
                ct++;
            }
        }
        return stones.size()-ct;

        
        
        
    }
};