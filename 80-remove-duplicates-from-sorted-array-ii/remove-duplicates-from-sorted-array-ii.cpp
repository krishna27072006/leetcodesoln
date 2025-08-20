class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;

        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
        }

        for(auto t : m){
            int cnt = min(2, t.second);  
            for(int i=0;i<cnt;++i){
                v.push_back(t.first);
            }
        }

        nums = v;  
        return v.size();
    }
};
