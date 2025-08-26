class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int maxi=0;
        int maxarea=0;
        for(int i=0;i<d.size();++i){
            int p=d[i][0]*d[i][0]+d[i][1]*d[i][1];
            int q=d[i][0]*d[i][1];
            if(p>maxi){
                maxi=p;
                maxarea=q;
            }else if(p==maxi){
                if(q>maxarea){
                    maxarea=q;
                }

            }
        }
        return maxarea;
        
    }
};