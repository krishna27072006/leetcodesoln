class Solution {
public:
    string arrangeWords(string text) {
        vector<string> v;
        stringstream ss(text);
        string word;
        while(ss>> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            v.push_back(word);
        }

        map<int,vector<string>> m;
        for(int i=0;i<v.size();++i){
            int t=v[i].size();
            m[t].push_back(v[i]);
        }
        string ans="";
        for(auto t : m){
            for(int i=0;i<t.second.size();++i){
                ans+=t.second[i];
                ans+=" ";
            }

        }
        ans[0]=toupper(ans[0]);
        ans.pop_back();
        return ans;

        
    }
};