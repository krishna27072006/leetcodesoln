
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> ns;
        stack<int> ps;
        for(int i=n-1;i>=0;--i){
            while(!ns.empty() && heights[ns.top()]>=heights[i]){
                ns.pop();
            }
            if(ns.empty()){
                nse[i]=n;
            }else{
                nse[i]=ns.top();
            }
            ns.push(i);
        }
        for(int i=0;i<n;++i){
            while(!ps.empty() && heights[ps.top()]>heights[i]){
                ps.pop();
            }
            if(ps.empty()){
                pse[i]=-1;
            }else{
                pse[i]=ps.top();
            }
            ps.push(i);
        }

        int mod=1e9+7;
        int ans=-1;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int  right =nse[i]-i;
            int total=nse[i] - pse[i] - 1;
            ans=max(ans,int(total*heights[i]));
            
           
        }
        return ans;
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area=largestRectangleArea(height);
            ans=max(ans,area);

        }
        return ans;
        
    }
};