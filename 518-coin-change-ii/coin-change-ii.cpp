class Solution {
public:
    int f(int i,int amount,vector<int> & coin,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coin[0]==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take=f(i-1,amount,coin,dp);
        int take=0;
        if(amount>=coin[i]){
            take=f(i,amount-coin[i],coin,dp);
        }
        return dp[i][amount]= take+not_take;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);

    }
};