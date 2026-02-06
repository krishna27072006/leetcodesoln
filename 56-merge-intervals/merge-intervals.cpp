class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] <b[0];   // bigger first element comes first
        });

        vector<int> c;
        vector<vector<int>> ans;
        c=intervals[0];
        for(int i=0;i<intervals.size();++i){
            if(c[1]>=intervals[i][0]){
                c[1]=max(intervals[i][1],c[1]);
            }else{
                ans.push_back(c);
                c[0]=intervals[i][0];
                c[1]=intervals[i][1];
            }
        }
        ans.push_back(c);
        return ans;
    }
};