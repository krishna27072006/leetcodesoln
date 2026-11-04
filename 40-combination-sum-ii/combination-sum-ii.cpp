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
        f(v,target,a,sum+c[i],i+1,c);
        a.pop_back();
        while (i+1<c.size() && c[i]==c[i+1]){
               i++;
        }
        f(v,target,a,sum,i+1,c);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> a;
        sort(candidates.begin(), candidates.end());
        f(v,target,a,0,0,candidates);
        return v;
    }
};