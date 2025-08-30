class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(),coins.end());
        long long reach=1;
        for(auto t : coins){
            if(t>reach) break;
            reach+=t;
        } 
        return (int)reach;
    }
};
