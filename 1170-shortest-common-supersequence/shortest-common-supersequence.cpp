class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<=n;++i) dp[i][0]=0;
        for(int i=0;i<=m;++i) dp[0][i]=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        int len=n+m-dp[n][m];
        string ans="";
        for(int i=0;i<len;++i){
            ans+='&';
        }
        int i=n;
        int j=m;
        int index=len-1;
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans[index] = str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans[index] = str1[i-1];
                index--;
                i--;
            }
            else {
                ans[index] = str2[j-1];
                index--;
                j--;
            }
        }

        while(i > 0) {
            ans[index] = str1[i-1];
            index--;
            i--;
        }

        while(j > 0) {
            ans[index] = str2[j-1];
            index--;
            j--;
        }

        return ans;
        
        
    }
};