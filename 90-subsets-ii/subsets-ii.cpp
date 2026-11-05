class Solution {
public:
    void f(vector<vector<int>> & v,vector<int> & a,vector<int> & nums,int i){
        if(i>=nums.size()){
            v.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        f(v,a,nums,i+1);
        a.pop_back();

        while(i<nums.size()-1 && nums[i]==nums[i+1]){
             i++;
        }
        f(v,a,nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        vector<int> a;
        f(v,a,nums,0);
        return v;


    }
};