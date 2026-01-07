class Solution {
public:
    void genrate(int i,int target,vector<int>& c,vector<int> v,vector<vector<int>>& ans){
        int sum=0;
        for(auto t : v) sum+=t;
        if(sum==target){
            ans.push_back(v);
            return;
        }
        if(sum>target || i>=c.size()) return;

        v.push_back(c[i]);
        genrate(i,target,c,v,ans);
        v.pop_back();
        genrate(i+1,target,c,v,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        genrate(0,target,c,v,ans);
        return ans;

        
    }
};