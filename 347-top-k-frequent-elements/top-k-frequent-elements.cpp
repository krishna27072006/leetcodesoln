class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]+=1;
        }
        for(auto t :m){
            pq.push({t.second,t.first});

        }
        
        for(int i=0;i<k;++i){
            int t=pq.top().second;
            ans.push_back(t);
            pq.pop();
        }
        return ans;
        
        
    }
};