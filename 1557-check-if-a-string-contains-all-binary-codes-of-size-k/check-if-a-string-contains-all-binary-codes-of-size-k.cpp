class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        set<string> set;
        for (int i=0;i<=n-k;i++) {
        set.insert(s.substr(i, k));
        }
        int p=pow(2,k);
        if(p==set.size()){
            return true;
        }else{
            return false;
        }
        
    }
};