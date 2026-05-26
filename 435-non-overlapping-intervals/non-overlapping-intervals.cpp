class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int ct=1;
        int freetime=intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]>=freetime){
                ct++;
                freetime=intervals[i][1];

            }
        }

        return n-ct;


    }
};