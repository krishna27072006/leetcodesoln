class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int> m;
       for(int i=0;i<tasks.size();++i){
        m[tasks[i]]+=1;

       }
       int maxi=-1;
       for(auto t : m){
        maxi=max(maxi,t.second);
       }
       int countMax = 0;

        for(auto t : m){
        if(t.second == maxi)
        countMax++;

        
}
int ans=(maxi-1)*(n+1)+countMax;
        return max((int)tasks.size(), ans);


        
    }
};