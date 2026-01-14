class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int total=1<<n;
        for(int i=0;i<total;++i){
            v.push_back(i^(i>>1));
        }
        return v;
        
    }
};