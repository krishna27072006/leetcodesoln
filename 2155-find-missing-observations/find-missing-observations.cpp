class Solution {
public:
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int m=r.size();
        int p=n+m;
        int sum=accumulate(r.begin(),r.end(),0);
        int t=mean*p-sum;
        vector<int> v;
        if(t<n){
            return v;
        }else if(t>6*n){
            return v;
        }else{
            int q=t/n;
            for(int i=0;i<n;++i){
                v.push_back(q);
            }
            for(int i=0;i<(t%n);++i){
                v[i]++;
            }
        }
        return v;
        
        
    }
};