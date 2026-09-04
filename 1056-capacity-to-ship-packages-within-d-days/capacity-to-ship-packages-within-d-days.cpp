class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        for(int i=0;i<weights.size();++i){
            high+=weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int count =1;
            int sum=weights[0];
            for(int i=1;i<weights.size();++i){
                
                if(sum+weights[i]>mid){
                    count++;

                    sum=weights[i];
                }else{
                    sum+=weights[i];
                }
            }
            if(count<=days){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};