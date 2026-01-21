class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> sub;
        for(int i=0;i<(1<<n);++i){
            vector<int> v(n,0);
            int j=0;
            int x=i;
            while(j<n){
                int r=x%2;
                x=x/2;
                v[j]=r;
                j++;
            }
            vector<int> p;
            for(int k=0;k<v.size();++k){
                if(v[k]==1){
                    p.push_back(nums[k]);

                }
            }
            sub.push_back(p);
        }
        unordered_map<int,int> m;
        for(int i=0;i<sub.size();++i){
            int p=0;
            for(int j=0;j<sub[i].size();++j){
                p= p| sub[i][j];
            }
            m[p]++;
        }
        vector<int> q;
        for(auto t : m){
            q.push_back(t.second);
        }
        int max=*max_element(q.begin(),q.end());
        return max;
        
    }
};