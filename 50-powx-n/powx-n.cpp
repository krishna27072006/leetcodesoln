class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            return 1.0/power(x,-(long long )n);

        }
        return power(x,n);
        
    }
double power(double x, long long int n){
    if(n==0) return 1;
    double half= power(x,n/2);
    if(n%2==0) return half*half;
    return half*half*x;
}

};