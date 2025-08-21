class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> v;
        long long sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            v.push_back(sum);
        }
        for(int i=n-1;i>=2;--i){
            if(v[i-1]>nums[i]){
                return v[i];
                break;
            }
        }
        return -1;
    }
};