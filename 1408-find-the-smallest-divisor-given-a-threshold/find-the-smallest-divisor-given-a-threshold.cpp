class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<nums.size();++i){
                count+=ceil((double)nums[i]/mid);
            }
            if(count<=threshold){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
        

        
    }
};