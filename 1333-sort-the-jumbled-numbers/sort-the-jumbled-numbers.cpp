class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();++i){
            int n=nums[i];
            int p=0;
            int s=1;
            if(n==0) p=m[0];
            while(n>0){
                int d=n%10;
                p+=s*m[d];
                s=s*10;
                n=n/10;
            }
            v.push_back({p,i});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<v.size();++i){
            ans.push_back(nums[v[i].second]);
        }
        return ans;

        
    }
};