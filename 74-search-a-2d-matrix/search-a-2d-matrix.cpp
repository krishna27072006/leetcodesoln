class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(high+low)/2;
            int i=mid/m;
            int j=mid%m;
            if(nums[i][j]==target){
                return true;
            }else if(nums[i][j]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
        
    }
};