class Solution {
public:

    void genrate(int i,string s,vector<string>& v,vector<vector<char>>& b){
        if(s.size()==b.size()){
            v.push_back(s);
            return;
        }
        if(i>=b.size()) return;

        for(auto c : b[i]){
            genrate(i+1,s+c,v,b);
        }

        
    }
    vector<string> letterCombinations(string d) {
        unordered_map<char,vector<char>> m;
        vector<string> v;
        string s="";
        
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        vector<vector<char>> b;
        for(int i=0;i<d.size();++i){
            b.push_back(m[d[i]]);
        }
        genrate(0,s,v,b);  
        return v;

    }
};