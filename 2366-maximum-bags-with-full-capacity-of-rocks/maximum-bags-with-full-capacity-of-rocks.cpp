class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int k=a;
        vector<int> v;
        for(int i=0;i<c.size();++i){
            v.push_back(c[i]-r[i]);
        }
        int ct=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i){
            k=k-v[i];
            if(k<0) break;
            ct++;
        }
        return ct;
        
    }
};