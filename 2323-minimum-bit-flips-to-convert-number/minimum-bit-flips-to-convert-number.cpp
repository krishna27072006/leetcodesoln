class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int ct=0;
        while(ans>1){
            if(ans%2==1) ct++;
            ans=ans/2;
        }
        if(ans==1) ct++;
        return ct;
        
    }
};