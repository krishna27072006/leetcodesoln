class Solution {
public:

    int f(int i, string &s,
          vector<int> &dp,
          vector<vector<bool>> &palindrom_vec) {

        if(i == s.size()) {
            return -1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int mini = 1e9;

        for(int j = i; j < s.size(); ++j) {

            if(palindrom_vec[i][j]) {

                int cuts = 1 + f(j + 1, s, dp, palindrom_vec);

                mini = min(mini, cuts);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, -1);
        vector<vector<bool>> palindrom_vec(
            n, vector<bool>(n, false)
        );

        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {

                if(s[i] == s[j] &&
                   (j - i <= 1 ||
                    palindrom_vec[i + 1][j - 1])) {

                    palindrom_vec[i][j] = true;
                }
            }
        }

        return f(0, s, dp, palindrom_vec);
    }
};