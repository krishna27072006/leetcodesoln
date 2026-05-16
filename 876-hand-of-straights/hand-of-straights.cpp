class Solution {
public:
    bool isNStraightHand(vector<int>& h, int g) {
        if (h.size() % g != 0) return false;

        map<int,int> m;
        for (auto t : h) m[t]++;

        for (auto& t : m) {
            int card = t.first;
            int count = t.second;
            if (count > 0) {
                for (int i = 1; i < g; ++i) {
                    if (m[card + i] < count) return false;
                    m[card + i] -= count;   
                }
                
                m[card] -= count;
            }
        }
        return true;
    }
};
