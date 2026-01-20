class Solution {
public:
    int kthLargestValue(vector<vector<int>>& m, int k) {
        int r = m.size(), c = m[0].size();
        vector<int> v;
        vector<vector<int>> pre(r, vector<int>(c, 0));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                pre[i][j] = m[i][j];
                if (i > 0) pre[i][j] ^= pre[i - 1][j];
                if (j > 0) pre[i][j] ^= pre[i][j - 1];
                if (i > 0 && j > 0) pre[i][j] ^= pre[i - 1][j - 1];

                v.push_back(pre[i][j]);
            }
        }

        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        return v[k - 1];
    }
};
