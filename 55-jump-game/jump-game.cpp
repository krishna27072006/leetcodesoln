class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        
        vector<int> v;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                v.push_back(i);
            }
        }
        if(v.empty()) return true;

        for(int i=0;i<v.size();++i){
            if (v[i]==nums.size()-1) return true;
            bool check=false;;
            for(int j=0;j<v[i];++j){
                if(nums[j]+j>v[i]){
                    check=true;
                    break;
                }
            }
            if(!check){
                return false;
            }
        }
        return true;
    }
};