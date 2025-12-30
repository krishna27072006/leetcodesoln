class Solution {
public:

    void genrate(int i,int n,vector<int>& v,vector<vector<int>>& ans,vector<int>nums){
        if(i>=n){
            ans.push_back(v);
            cout<<endl;
            return;
        }
        v.push_back(nums[i]);
        genrate(i+1,n,v,ans,nums);
        v.pop_back();
        genrate(i+1,n,v,ans,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;

        int n=nums.size();
        genrate(0,n,v,ans,nums);
        return ans;


        
    }
};