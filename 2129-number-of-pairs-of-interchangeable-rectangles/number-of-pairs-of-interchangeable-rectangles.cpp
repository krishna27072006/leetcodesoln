class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        unordered_map<string, long long> m;

        for (auto &rect : r) {
            int w = rect[0], h = rect[1];
            int g = gcd(w, h);
            w /= g, h /= g;
            string key = to_string(w) + "/" + to_string(h);
            m[key] += 1;
        }

        long long sum = 0;
        for (auto &t : m) {
            long long p = t.second;
            sum += p * (p - 1) / 2;
        }
        return sum;
    }
};

