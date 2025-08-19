class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int> v;
        int ct=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                ct++;
            }else {
                if(ct!=0){
                    v.push_back(ct);
                    ct=0;
                }
            }
        }
        v.push_back(ct);
        int max=*max_element(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<max;++i){
            for(int j=0;j<v.size();++j){
                if(v[j]>i){
                    ans+=v[j]-i;
                }
            }

        }
        return ans;  
    }
};