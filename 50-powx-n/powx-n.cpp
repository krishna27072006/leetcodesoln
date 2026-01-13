class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long  n1=llabs(n);
        while(n1>0){
            if(n1%2!=0){
                n1=n1-1;
                ans=ans*x;
            }else{
                n1=n1/2;
                x=x*x;

            }
            
        }
        if(n<0) return (1/ans);
        return ans;
        
    }
};