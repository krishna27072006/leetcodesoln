class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int max=-1;
        int n=height.size();
        int idx = max_element(height.begin(), height.end()) - height.begin();
        for(int i=0;i<=idx;++i){
            if(height[i]>max){
                max=height[i];
            }else{
                ans+=max-height[i];
            }


        }
        int max2=-1;
        for(int i=n-1;i>=idx;--i){
            if(height[i]>max2){
                max2=height[i];
            }else{
                ans+=max2-height[i];
            }
        }
        return ans;
        
    }
};