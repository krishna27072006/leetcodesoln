class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int t=0;
        for(int i=0;i<d.size();++i){
            t=t^d[i];
        }
        if(t==0){
            return true;
        }else{
            return false;
        }
    }
};