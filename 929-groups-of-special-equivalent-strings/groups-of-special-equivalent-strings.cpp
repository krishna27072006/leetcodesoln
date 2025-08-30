class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string,string>> s;
        for(int i=0;i<words.size();++i){
            string e="";
            string o="";
            for(int j=0;j<words[i].size();++j){
                if(j%2==0){
                    e+=words[i][j];
                }else{
                    o+=words[i][j];  } }
            sort(e.begin(),e.end());
            sort(o.begin(),o.end());
            s.insert({e,o});
        }
        return s.size();
        
    }
};