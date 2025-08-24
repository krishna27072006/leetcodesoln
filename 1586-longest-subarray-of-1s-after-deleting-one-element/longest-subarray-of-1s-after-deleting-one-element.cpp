class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        vector<int> v1;
        v.push_back(-1);
        int maxi=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                v.push_back(i);
            }
        }
        v.push_back(nums.size());
        if(v.size()==2) return nums.size()-1;
        for(int i=0;i<v.size()-1;++i){
            int p=v[i+1]-v[i]-1;
            v1.push_back(p);

        }
        for(int i=0;i<v1.size()-1;++i){
            maxi=max(maxi,v1[i]+v1[i+1]);

        }
        return maxi;

          
        
    }
};