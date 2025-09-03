class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        vector<int> col1;
        vector<int> row1;
        vector<int> col0;
        vector<int> row0;
        vector<vector<int>> d = g;

        for(int i=0; i<g.size(); ++i){
            int ct=0;
            for(int j=0; j<g[0].size(); ++j){
                if(g[i][j]==1) ct++;
            }
            row1.push_back(ct);
            row0.push_back(g[0].size()-ct);
        }

        for(int j=0; j<g[0].size(); ++j){
            int ct=0;
            for(int i=0; i<g.size(); ++i){
                if(g[i][j]==1) ct++;
            }
            col1.push_back(ct);
            col0.push_back(g.size()-ct);
        }

        for(int i=0; i<g.size(); ++i){
            for(int j=0; j<g[0].size(); ++j){
                int p = row1[i] + col1[j] - row0[i] - col0[j];
                d[i][j] = p;
            }
        }
        return d;
    }
};