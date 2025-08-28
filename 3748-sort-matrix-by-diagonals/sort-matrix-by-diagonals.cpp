class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> v(n, vector<int>(n));
        unordered_map<int, vector<int>> m;

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m[i - j].push_back(g[i][j]);
            }
        }

        
        for (auto& t : m) {  
            if (t.first >= 0) {
                sort(t.second.begin(), t.second.end());
            } else {
                sort(t.second.rbegin(), t.second.rend()); 
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto& vec = m[i - j];
                v[i][j] = vec.back();
                vec.pop_back();
            }
        }

        return v;
    }
};
