class Solution {
public:
    int f(int i ,int amount,vector<int> & coin,vector<vector<int>> &dp ){
        if(amount==0){
            return 0;
        }
        if(i==0){
            if(amount%coin[0]==0){
                return amount/coin[0];
            }else{
                return 1e9;
            }
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int not_take=f(i-1,amount,coin,dp);
        int same_take=1e9;
        if(coin[i]<=amount){
            same_take=1+f(i,amount-coin[i],coin,dp);
        }
        return dp[i][amount]=min(not_take,same_take);
        

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = f(n-1,amount,coins,dp);

        

        for(int i=0;i<=amount;++i){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }

        for(int i=1;i<n;++i){
            for(int j=0;j<=amount;++j){
                int not_take=dp[i-1][j];
                int same_take=1e9;
                if(coins[i]<=j){
                    same_take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(not_take,same_take);

            }
        }
        int ans=dp[n-1][amount];
        if (ans >= 1e9)
            return -1;

        return ans;
    }
};