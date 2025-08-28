class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        vector<pair<int,char>> v;
        for(char c : s){
            m[c] += 1;
        }
        for(auto t : m){
            v.push_back({t.second, t.first});
        }

        vector<int> a;
        int ct = 0;
        a.push_back(-1);

        for(int i=0;i<v.size();++i){
            auto it = find(a.begin(), a.end(), v[i].first);
            bool ch = false;

            if(it != a.end()){  
                for(int j=1; j<v[i].first; ++j){   // ✅ fixed j instead of i
                    auto t = find(a.begin(), a.end(), v[i].first - j);
                    if(t == a.end()){
                        ct += j;                           // ✅ delete j chars
                        a.push_back(v[i].first - j);       // ✅ push reduced freq
                        ch = true;
                        break;
                    }
                }
                if(!ch){
                    ct += v[i].first;   // delete all
                }
            } else {
                a.push_back(v[i].first);
            }
        }
        return ct;
    }
};
