class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> v;
        v.push_back(pref[0]);
        for(int i=1;i<n;++i){
            int x=pref[i]^pref[i-1];
            v.push_back(x);
        }
        return v;
        
    }
};