class Solution {
public:
    void f(vector<int> &num,vector<vector<int>> &v,int i,vector<int> a){
        if(i>=num.size()){
            v.push_back(a);
            return;
        }
        a.push_back(num[i]);
        f(num,v,i+1,a);
        a.pop_back();
        f(num,v,i+1,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> a;
        f(nums,v,0,a);
        return v;
         
    }
};