class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(high+low)/2;
            int col=0;
            for(int i=0;i<m;++i){
                if(mat[mid][i]>mat[mid][col]){
                    col=i;
                }
            }
            int top=-1;
            int bottom=-1;
            if(mid>0){
                top=mat[mid-1][col];
            }
            if(mid<n-1){
                bottom=mat[mid+1][col];
            }
            if(bottom<mat[mid][col] && top<=mat[mid][col]){
                return {mid,col};
            }else if(top>mat[mid][col]){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return {-1,-1};


    }
};