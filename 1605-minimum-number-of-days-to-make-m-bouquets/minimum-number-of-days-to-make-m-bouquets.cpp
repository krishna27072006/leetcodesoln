class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        int maxi=*max_element(b.begin(),b.end());
        int low=1;
        int high=maxi;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(high+low)/2;
            int flowers = 0;
            int bouquets = 0;

            for(int i = 0; i < n; i++) {
                  if(b[i] <= mid) {
                       flowers++;

                   if(flowers == k) {
                           bouquets++;
                           flowers = 0;
                      }
                }
                       else {
                      flowers = 0;
                    }
                }
            if(bouquets>=m){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        if(ans!=INT_MAX){
            return ans;
        }else{
            return -1;
        }
    }
};