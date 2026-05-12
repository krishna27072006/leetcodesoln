class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> nge(n);
        vector<int> pge(n);
        
        stack<int> ng;
        stack<int> pg;

        // NEXT GREATER
        for(int i=n-1;i>=0;--i){
            while(!ng.empty() && nums[ng.top()]<=nums[i]){
                ng.pop();
            }

            if(ng.empty()){
                nge[i]=n;
            }else{
                nge[i]=ng.top();
            }

            ng.push(i);
        }

        // PREVIOUS GREATER
        for(int i=0;i<n;++i){
            while(!pg.empty() && nums[pg.top()]<nums[i]){
                pg.pop();
            }

            if(pg.empty()){
                pge[i]=-1;
            }else{
                pge[i]=pg.top();
            }

            pg.push(i);
        }

        long long ans=0;

        // SUM OF MAXIMUMS
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;

            ans += 1LL * nums[i] * left * right;
        }

        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> ns;
        stack<int> p;

        // NEXT SMALLER
        for(int i=n-1;i>=0;--i){
            while(!ns.empty() && nums[ns.top()]>=nums[i]){
                ns.pop();
            }

            if(ns.empty()){
                nse[i]=n;
            }else{
                nse[i]=ns.top();
            }

            ns.push(i);
        }

        // PREVIOUS SMALLER
        for(int i=0;i<n;++i){
            while(!p.empty() && nums[p.top()]>nums[i]){
                p.pop();
            }

            if(p.empty()){
                pse[i]=-1;
            }else{
                pse[i]=p.top();
            }

            p.push(i);
        }

        long long ans1=0;

        // SUM OF MINIMUMS
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;

            ans1 += 1LL * nums[i] * left * right;
        }

        return ans-ans1;
    }
};