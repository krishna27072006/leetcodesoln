class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int rs=0;
        int ls=0;
        for(int i=0;i<k;++i){
            ls+=nums[i];
        }
        int j=nums.size()-1;
        int ans=ls;
        for(int i=k-1;i>=0;--i){
            ls=ls-nums[i];
            rs+=nums[j];
            j=j-1;
            ans=max(ans,rs+ls);
        }
        return ans;
    }
};