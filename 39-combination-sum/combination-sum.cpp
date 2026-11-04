class Solution {
public:
    void f(vector<vector<int>> &v,int &target,vector<int> &a,int sum,int i,vector<int>& c){
        if(sum==target){
            v.push_back(a);
            return;
        }
        if(sum>target || i>=c.size()){
            return;
        }
        a.push_back(c[i]);
        f(v,target,a,sum+c[i],i,c);
        a.pop_back();
        f(v,target,a,sum,i+1,c);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> a;
        f(v,target,a,0,0,candidates);
        return v;
    }
};