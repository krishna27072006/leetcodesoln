class DisjointSet {
    

public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int dc[]={0,1,0,-1};
        int dr[]={1,0,-1,0};
        DisjointSet ds(n*n);
        for(int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if(grid[i][j]==0) continue;
                int node=i*n+j;
                for(int k=0;k<4;++k){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    int node2=nr*n+nc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        ds.unionBySize(node,node2);
                    }
                }

            }
        }
        int ans=0;
        for (int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    set<int> s;
                    for(int k=0;k<4;++k){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int node2=nr*n+nc;
                            s.insert(ds.findUPar(node2));
                        }
                    }
                    int area=1;

                    for(auto t : s){
                        area+=ds.size[t];

                    }
                    ans=max(ans,area);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }
        return ans;
        
        
    }
};