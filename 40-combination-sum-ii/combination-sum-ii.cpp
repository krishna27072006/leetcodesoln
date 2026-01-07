class Solution {
public:

    void genrate(int i,int t,vector<int>& c,vector<int>& v,vector<vector<int>>& ans){
        int sum=0;
        for(int i=0;i<v.size();++i){
            sum+=v[i];
        }
        if(sum==t){
            ans.push_back(v);
            return;
        }
        if(sum>t || i>=c.size()) return;
        v.push_back(c[i]);
        genrate(i+1,t,c,v,ans);
        v.pop_back();
        int n=i+1;
        while (n < c.size() && c[n] == c[i]) n++;
        genrate(n,t,c,v,ans);



    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        vector<int> v;
        genrate(0,t,c,v,ans);
        return ans;

        
    }
};