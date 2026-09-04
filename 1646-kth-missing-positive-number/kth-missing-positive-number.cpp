class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int high=arr.back()+k;
        int low=1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<arr.size();++i){
                if(arr[i]<=mid){
                    count++;
                }
            }
            int miss=mid-count;
            if(k<=miss){
                ans=mid;
                high=mid-1;
                
            }else{
                low=mid+1;
            }

        }
        if(ans!=-1){
            return ans;
        }else{
            return high+k;
        }
    }
};