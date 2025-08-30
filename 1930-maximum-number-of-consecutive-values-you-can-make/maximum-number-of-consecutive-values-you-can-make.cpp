class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(),coins.end());
        long long ans=1;
        for(auto t : coins){
            if(t>ans) break;
            ans+=t;
        } 
        return (int)ans;
    }
};
