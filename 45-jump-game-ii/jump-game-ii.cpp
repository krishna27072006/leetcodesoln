class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int f=0;
        int c=0;
        for(int i=0;i<nums.size()-1;++i){
            f=max(f,i+nums[i]);

            if(c==i){
                jump++;
                c=f;
            }
        }
        return jump;
        
    }
};