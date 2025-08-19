class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans=0;
        int ct=0;
        for(int i=0;i<p.size()-1;++i){
            if(p[i]-p[i+1]==1){
                ct++;
                ans+=ct;
            }else{
                ct=0;
            }
            ans++;
        }
        return ans+1;
    }
};