class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginword,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginword);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endword) return step;
            for(int i=0;i<word.size();++i){
                char original=word[i];
                for(char ch='a';ch<='z';++ch){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }

                }
                word[i]=original;
            }

        }
        return 0;
        
    }
};