class Solution {
public:

    void genrate(int i,string a,string s,vector<string>& b,vector<vector<string>>& v ){
        string c=a;
        reverse(c.begin(),c.end());

        if(i >= s.size()){                 
            if(a == c && a.size() > 0){    
                b.push_back(a);
                v.push_back(b);
                b.pop_back();
            }
            return;
        }

        if(a == c && a.size() > 0){
            b.push_back(a);
            genrate(i, "", s, b, v);
            b.pop_back();
        }

        a += s[i];
        genrate(i+1, a, s, b, v);

        a.pop_back();
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> b;
        string a="";
        genrate(0,a,s,b,v);
        return v;
    }
};
