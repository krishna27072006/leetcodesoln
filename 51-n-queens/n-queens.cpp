class Solution {
public:

    bool issafe(int row,int col,vector<string>& b,int n){
        int r1=row;
        int c1=col;
        while(row>=0 && col>=0){
            if(b[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=r1;
        col=c1;


        while(col>=0){
            if(b[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=r1;
        col=c1;
        while(row<n && col>=0){
            if(b[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;


    }

     void solve(int col,vector<string>& b,vector<vector<string>>& ans,int n){
        if(col==n){
            ans.push_back(b);
            return;
        }
        for(int row=0;row<n;++row){
            if(issafe(row,col,b,n)){
                b[row][col]='Q';
                solve(col+1,b,ans,n);
                b[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n, string(n, '.'));
        solve(0,b,ans,n);
        return ans;


        
        
    }
};