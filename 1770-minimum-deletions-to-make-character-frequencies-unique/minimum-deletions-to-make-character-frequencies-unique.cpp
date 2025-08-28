class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        vector<pair<int,char>> v;
        for(int i=0;i<s.size();++i){
            m[s[i]]+=1;
        }
        for(auto t : m){
            v.push_back({t.second,t.first});
        }
        vector<int> a;
        int ct=0;
        a.push_back(-1);
        for(int i=0;i<v.size();++i){
            auto it = find(a.begin(), a.end(), v[i].first);
            int ch=false;
            if(it!=a.end()){
                for(int j=1;j<v[i].first;++j){
                    
                    auto t=find(a.begin(), a.end(), v[i].first-j);
                    if(t==a.end()){
                        ct=ct+j;
                        a.push_back(v[i].first-j);
                        ch=true;
                        break;
                    }
                }
                if(!ch){
                ct=ct+v[i].first;
            }

            }else{
                a.push_back(v[i].first);
            }
            

        }
        return ct;



        
        
    }
};