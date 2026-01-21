class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        int count = 0;

        for (int mask = 0; mask < (1 << n); ++mask) {
            int currOR = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currOR |= nums[i];
                }
            }

            if (currOR > maxOR) {
                maxOR = currOR;
                count = 1;
            } 
            else if (currOR == maxOR) {
                count++;
            }
        }
        return count;
    }
};
