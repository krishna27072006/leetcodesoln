class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> v;
        for(int i=0;i<nums1.size();++i){
            stack<int> st;
            for(int j=nums2.size()-1;i>=0;--j){
                if(nums2[j]==nums1[i]){
                    break;
                }
                st.push(nums2[j]);
            }
            
            while(!st.empty()){
                if(st.top()>nums1[i]){
                    v.push_back(st.top());
                    break;
                }else{
                    st.pop();
                }
            }
            if(st.empty()){
                v.push_back(-1);
            }
        }
        return v;
    }
};