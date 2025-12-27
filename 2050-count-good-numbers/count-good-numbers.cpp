class Solution {
public:
    const long long mod = 1e9 + 7;

    long long power(long long x, long long y) {
        long long res = 1;
        x %= mod;
        while (y > 0) {
            if (y & 1) res = (res * x) % mod;
            y >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long ans = (power(5, even) * power(4, odd)) % mod;
        return ans;
    }
};
