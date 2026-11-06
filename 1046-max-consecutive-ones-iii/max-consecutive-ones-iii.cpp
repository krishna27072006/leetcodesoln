class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;
        int r=0;
        int l=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]==1){
               r++;
            }
            else if(nums[r]==0 && zero<k){
                r++;
                zero++;
            }else{
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};