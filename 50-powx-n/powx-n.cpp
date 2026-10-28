class Solution {
public:
    long double f(long double x,long long n){
        if(n==0){
            return 1.0L;
        }
       long  double half=f(x,n/2);
        if(n%2==0){
            return half*half;
        }else{
            return x*half*half;
        }
    }
    double myPow(double x, int n) {
        long long p=n;
        long double base=x;
        if(p<0){
            base=1.0L/base;
            p=-p;
        }
        return (double)f(base,p);
    }
};