class Solution {
public:
    void subset(int i,int n,vector<int>& v,set<vector<int>>& s,vector<int>& nums){
        if(i>=n){
            s.insert(v);
            cout<<endl;
            return;
        }
        v.push_back(nums[i]);
        subset(i+1,n,v,s,nums);
        v.pop_back();
        subset(i+1,n,v,s,nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        set<vector<int>> s;
        int n=nums.size();
        subset(0,n,v,s,nums);
        vector<vector<int>> ans;
        for(auto t : s){
            ans.push_back(t);

        }
        return ans;
        
    }
};