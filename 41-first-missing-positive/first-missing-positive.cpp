class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                v.push_back(nums[i]);
            }
        }
        if(v.size()==0)return 1;
        
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(int i=0;i<v.size();++i){
            if(v[i]!=i+1){
                return i+1;
                
            }
            
        }
        return v.size()+1;
    }
};