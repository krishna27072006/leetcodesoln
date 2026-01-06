class Solution {
public:
    void genrate(int open,int close,string s,vector<string>& v){
        
        if(open==0 && close==0){
            v.push_back(s);
            return;
        }
        if(open>0){
            genrate(open-1,close,s+'(',v);
        }
        if(close>open){
            genrate(open,close-1,s+')',v);
        }



    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> v;
        genrate(n,n,s,v);
        return v;
        

        
    }
};