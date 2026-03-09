class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> ns;
        stack<int> p;
        for(int i=n-1;i>=0;--i){
            while(!ns.empty() && arr[ns.top()]>=arr[i]){
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
            while(!p.empty() && arr[p.top()]>arr[i]){
                p.pop();
            }
            if(p.empty()){
                pse[i]=-1;
            }else{
                pse[i]=p.top();
            }
            
            p.push(i);
        }
        long long ans=0;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right =nse[i]-i;
            
            ans=(ans+(arr[i]*left*right) % mod)%mod;
        }
        
        return ans;
    }
};