class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int> &nums) {

        int n=nums.size();
        vector<vector<int> > ans;

        for(int i=0;i<(1<<n );++i){
            vector<int> v;
            vector<int> s(n,0);
            int p=i;
            int j=0;

            while(j<n){
                int d=p%2;
                s[j]=d;
                p=p/2;
                j++;
            }

            for(int k=0;k<n;++k){
                if(s[k]==1){
                    v.push_back(nums[k]);
                }
            }

            ans.push_back(v);
        }

        set<vector<int>> seen;   // ★ minimal fix

        vector<vector<int> > k;
        for(int i=0;i<ans.size();++i){
            if(ans[i].size()>1){
                bool check=true;
                for(int j=0;j<ans[i].size()-1;++j){
                    if(ans[i][j+1]<ans[i][j]){
                        check=false;
                        break;
                    }
                }

                if(check){
                    if(!seen.count(ans[i])){  // ★ block duplicates
                        seen.insert(ans[i]);
                        k.push_back(ans[i]);
                    }
                }
            }
        }

        return k;
    }
};
