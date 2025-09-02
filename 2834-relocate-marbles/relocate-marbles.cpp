class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
        unordered_set<int> s;
        for(auto t : nums){
            s.insert(t);
        }
        for(int i=0;i<mf.size();++i){
            if(s.count(mf[i])){
                s.erase(mf[i]);
                s.insert(mt[i]);
            }
        }
        vector<int> ans(s.begin(),s.end());
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};