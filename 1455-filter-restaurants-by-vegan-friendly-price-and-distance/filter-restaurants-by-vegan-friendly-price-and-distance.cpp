class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> v;
        vector<int> ans;
        
        for(int i=0;i<r.size();++i){
            if((r[i][3]<=maxPrice)&&(r[i][4]<=maxDistance)){
                if(veganFriendly==1){
                    if(r[i][2]==1){
                        v.push_back({r[i][1],r[i][0]});
                    }
                }else{
                    v.push_back({r[i][1],r[i][0]});
                    
                }
            }

        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();++i){
            ans.push_back(v[i].second);

        }
        return ans;
        
    }
};