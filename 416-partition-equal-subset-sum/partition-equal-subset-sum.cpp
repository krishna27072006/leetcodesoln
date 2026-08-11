class Solution {
public:
    bool f(int i,int target,vector<int> & nums,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(i==0){
            return (nums[0]==target);
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool not_take=f(i-1,target,nums,dp);
        bool take=false;
        if(target>=nums[i]){
            take=f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=take || not_take;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<nums.size();++i){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        vector<vector<int>> dp(n, vector<int>((total/2) + 1, -1));
        
        return f(n-1,total/2,nums,dp);


        
    }
};