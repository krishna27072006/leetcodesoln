class Solution {
public:
    vector<int> decode(vector<int>& e) {
        int n=e.size()+1;
        int x=0;
        for(int i=1;i<=n;++i){
            x=x^i;
        }

        int a=0;
        for(int i=0;i<n-1;i=i+2){
            a=a^e[i];
        }
        int last =x^a;
        vector<int> ans;
        ans.push_back(last);
        reverse(e.begin(),e.end());
        for(int i=0;i<e.size();++i){
            last=last^e[i];
            ans.push_back(last);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};