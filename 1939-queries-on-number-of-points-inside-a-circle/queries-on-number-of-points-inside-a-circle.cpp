class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<int> v;
        for(int i=0;i<q.size();++i){
            int x=q[i][0];
            int y=q[i][1];
            int r=q[i][2];
            int ct=0;
            for(int i=0;i<p.size();++i){
                int x1=p[i][0];
                int y1=p[i][1];
                if((x1-x)*(x1-x)+(y1-y)*(y1-y)<=r*r){
                    ct++;
                }

            }
            v.push_back(ct);
        }
        return v;
        
    }
};