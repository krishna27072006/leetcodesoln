class Solution {
public:
    int f(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {

        if(i == 0) {
            if(sum == 0 && arr[0] == 0)
                return 2;

            if(sum == 0 || sum == arr[0])
                return 1;

            return 0;
        }

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int not_take = f(i - 1, sum, arr, dp);

        int take = 0;
        if(arr[i] <= sum)
            take = f(i - 1, sum - arr[i], arr, dp);

        return dp[i][sum] = not_take + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = 0;
        for(int x : nums)
            total += x;

        if(abs(target) > total)
            return 0;

        if((total - target) % 2 != 0)
            return 0;

        int sum = (total - target) / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return f(n - 1, sum, nums, dp);
    }
};