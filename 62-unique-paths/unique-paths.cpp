class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;++i){
            vector<int> curr(n,0);
            for(int j=0;j<n;++j){
                if(i==0 && j==0){
                    curr[j]=1;
                }else{
                    int a=0;
                    int b=0;
                    
                        a=prev[j];
                    
                    if(j>0){
                        b=curr[j-1];
                    }
                    curr[j]=a+b;
                }

            }
            prev=curr;
        }
        return prev[n-1];

        
    }
};