class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=1e5;++i){
            string s1=to_string(i);
            reverse(s1.begin(),s1.end());
            int n=stoi(s1);
            if(n+i==num){
                return true;
            }
            
        }
        return false;
        
    }
};