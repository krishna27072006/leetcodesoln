class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans=true;
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<bills.size();++i){
            if(bills[i]==5){
                a++;
            }else if(bills[i]==10){
                b++;
            }else{
                c++;
            }
            if(bills[i]==10){
                if(a==0){
                    ans=false;
                    break;
                }else{
                    a--;
                }
            }else if(bills[i]==20){
               if(b > 0 && a > 0) {
                    b--;
                    a--;
                } else if(a >= 3) {
                    a -= 3;
                } else {
                    ans= false;
                }
            }
        }
        return ans;

        
    }
};