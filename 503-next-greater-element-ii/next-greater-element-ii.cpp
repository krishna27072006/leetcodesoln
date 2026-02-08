class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        unordered_map<int,int> m;
        for(int i=2*nums.size()-1;i >=0;i--){
            int t=i%nums.size();
            while(!st.empty() && nums[st.top()]<=nums[t]){
                st.pop();
            }
            if(i<nums.size()){
            if(st.empty()){
                m[t]=-1;

            }else{
                m[t]=nums[st.top()];
            }
            }
            st.push(t);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            ans.push_back(m[i]);
        }
        return ans;
        
    }
};