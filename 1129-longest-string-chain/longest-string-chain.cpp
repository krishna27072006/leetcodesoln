class Solution {
public:
    bool check(string s1,string s2){
        if(s1.size()!=s2.size()+1) return false;
        int first=0;
        int second =0;
        while(first < s1.size() && second < s2.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++;
            }

        }
        return second==s2.size();

    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
             return a.size() < b.size();
            });
        int n=arr.size();
        int maxi=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int prev=0;prev<i;++prev){
                if(check(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};