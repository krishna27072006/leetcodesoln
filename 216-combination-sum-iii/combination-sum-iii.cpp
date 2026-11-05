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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        for(int i=0;i<9;++i){
            a.push_back(i+1);
        }
        vector<vector<int>> v;
        vector<int> temp;
        f(v,n,temp,0,0,a);
        v.erase(
            remove_if(v.begin(), v.end(), [&](vector<int>& a) {
            return a.size() != k;
            }),
          v.end()
        );
        return v;
    }
};