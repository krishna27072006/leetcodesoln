class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int high=0;
        for(int i=0;i<n;++i){
            high+=nums[i];
        }
        int ans=INT_MAX;
        int low=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            int sum=0;
            for(int i=0;i<n;++i){
                if(sum+nums[i]>mid){
                    count++;
                    sum=nums[i];
                }else{
                    sum+=nums[i];
                }
            }
            if(count+1<=m){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};