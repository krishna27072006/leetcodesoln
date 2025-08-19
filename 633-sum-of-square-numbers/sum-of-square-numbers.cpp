class Solution {
public:
    bool judgeSquareSum(int c) {
        
        vector<long long> v;
        for(long long  i=0;i*i<=c;++i){
            v.push_back(i*i);
        }
        int l=0;
        int r=v.size()-1;
        while(l<=r){
            if(v[r]+v[l]>c){
                r--;
            }else if(v[r]+v[l]<c){
                l++;
            }else{
                return true;
                break;
            }
        }
        return false;
    }
};