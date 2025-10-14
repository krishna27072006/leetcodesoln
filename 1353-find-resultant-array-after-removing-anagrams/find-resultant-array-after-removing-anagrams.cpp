class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";

        for (string w : words) {
            string sorted = w;
            sort(sorted.begin(), sorted.end());

            if (sorted != prev) {  
                ans.push_back(w);
                prev = sorted;
            }
        }
        return ans;
    }
};
