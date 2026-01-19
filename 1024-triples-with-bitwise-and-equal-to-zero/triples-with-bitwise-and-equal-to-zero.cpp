class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size();++j){
                m[nums[i]&nums[j]]++;
            }
        }
        int ct=0;
        for(int i=0;i<nums.size();++i){
            for(auto &t:m){
                if((t.first & nums[i])==0){
                    ct+=t.second;
                }
            }
        }
        return ct;
    }
};