class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n=arr.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;++i){
            pre[i+1]=pre[i]^arr[i];
        }
        vector<int> ans;
        for(int i=0;i<q.size();++i){
            int l=q[i][0];
            int r=q[i][1];
            int a=pre[l]^pre[r+1];
            ans.push_back(a);
             

        }
        return ans;


        
    }
};