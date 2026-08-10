class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;

    for(int i=0;i<triangle.size();i++) {
        dp.push_back(vector<int>(triangle[i].size(), -1));
    }
    for(int i=0;i<dp.size();++i){
        for(int j=0;j<dp[i].size();++j){
            if(i==0 && j==0){
                dp[i][j]=triangle[i][j];
                continue;
            }
            int left=1e9;
            int right=1e9;
            if(j==0){
                right=dp[i-1][j];
            }
            else if(j==triangle[i].size()-1){
                left=dp[i-1][j-1];
            }
            else{
                right=dp[i-1][j];
                left=dp[i-1][j-1];
            }
            dp[i][j]=triangle[i][j]+min(left,right);



        }
    }
    int mini=1e9;
    for(int i=0;i<triangle[triangle.size()-1].size();++i){
        mini=min(mini,dp[dp.size()-1][i]);
    }
    return mini;

        
    }
};