class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num : nums){
            string s = to_string(num);
            reverse(s.begin(), s.end());
            int revNum = stoi(s);
            m[num - revNum]++;   
        }

        long long sum = 0;
        const int MOD = 1e9 + 7;

        for(auto &t : m){
            long long p = t.second;   
            sum = (sum + p*(p-1)/2) % MOD;
        }
        return (int)sum;
    }
};
