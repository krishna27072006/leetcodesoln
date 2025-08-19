class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0;
        int ct=1;
        for(int i=0;i<s.size();++i){
            if((int)s[i+1]-(int)s[i]==1){
                ct++;
            }else{
                ans=max(ans,ct);
                ct=1;
            }

        }
        return ans;
        
    }
};