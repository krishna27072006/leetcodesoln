class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        return fastpow(x, m);
    }

    double fastpow(double x, long long n) {
        if (n == 0) return 1.0;

        double half = fastpow(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
