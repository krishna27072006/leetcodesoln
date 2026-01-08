class Solution {
public:
    void genrate(int i,int k,vector<int>& temp,vector<vector<int>>& ans,vector<int>& v){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        if(i>=v.size()) return;
        temp.push_back(v[i]);
        genrate(i+1,k,temp,ans,v);
        temp.pop_back();
        genrate(i+1,k,temp,ans,v);



    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for(int i=0;i<9;++i){
            v.push_back(i+1);
        }
        vector<vector<int>> ans;
        vector<vector<int>> f;
        vector<int> temp;
        genrate(0,k,temp,ans,v);

        for(int i=0;i<ans.size();++i){
            int sum=0;
            for(int j=0;j<ans[i].size();++j){
                sum+=ans[i][j];
            }
            if(sum==n){
                f.push_back(ans[i]);

            }
        }
        return f;

    
        
    }
};