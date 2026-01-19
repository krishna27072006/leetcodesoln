class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int> v;
        for(int i=0;i<s.size();++i){
            if(isalpha(s[i])){
                v.push_back(i);
            }
        }
        vector<string> ans;
        int n=v.size();
        for(int i=0;i<(1<<n);++i){
            string temp=s;
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    temp[v[j]]=toupper(temp[v[j]]);
                }else{
                    temp[v[j]]=tolower(temp[v[j]]);
                }
            }
            ans.push_back(temp);

        }
        return ans;
    }
};