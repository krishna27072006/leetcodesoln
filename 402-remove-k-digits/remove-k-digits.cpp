class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.size();++i){
            while(!st.empty() && k>0 && st.top()>num[i]){
                    st.pop();
                k--;
                
            }
            st.push(num[i]);
            
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        
        reverse(ans.begin(),ans.end());
        while(ans.size()>1 && ans[0]=='0'){ 
            ans.erase(ans.begin());
        }
        return ans=="" ? "0" : ans;
    }
};