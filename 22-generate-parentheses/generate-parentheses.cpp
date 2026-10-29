class Solution {
public:
    void f(int open ,int close,vector<string> &ans,string &s){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s+='(';
            f(open-1,close,ans,s);
            s.pop_back();
        }
        if(close>open){
            s+=')';
            f(open,close-1,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
           vector<string> ans;
           string s="";
           int open=n;
           int close=n;
           f(open,close,ans,s);
           return ans;
        
    }
};