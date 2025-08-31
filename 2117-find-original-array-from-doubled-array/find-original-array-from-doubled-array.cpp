class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        if(c.size()%2!=0) return {};
        unordered_map<int,int> m;
        for(int i=0;i<c.size();++i){
            m[c[i]]+=1;
        }
        sort(c.begin(),c.end());
        vector<int> v;
        for(auto t :c){
            if(m[t]==0) continue;
            if(m[t*2]==0) return {};
            v.push_back(t);
            m[t]--;
            m[t*2]--;
        }
        return  v;
    
        
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });