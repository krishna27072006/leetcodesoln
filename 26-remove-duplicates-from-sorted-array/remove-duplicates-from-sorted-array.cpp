class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       set<int> s;
       for(auto p: nums){
        s.insert(p);
       }
       int n=s.size();
       int j=0;
       for(auto p:s){
        nums[j++]=p;
       }
       return n;
    }
};