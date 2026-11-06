class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int ans=0;
        int l=0;
        int r=0;
        int n=s.size();
        while(r<n){
            while(ch.find(s[r])!=ch.end()){
                ch.erase(s[l]);
                l++;
            }

            ch.insert(s[r]);
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};