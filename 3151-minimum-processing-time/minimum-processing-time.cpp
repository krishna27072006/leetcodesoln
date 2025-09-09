class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        sort(t.begin(),t.end());
        sort(pt.rbegin(),pt.rend());
        vector<int> v;
        int ct=0;
        for(int i=0;i<t.size();i=i+4){

            v.push_back(t[i+3]+pt[ct]);
            ct++;

        }
        int max=*max_element(v.begin(),v.end());
        return max;

        

        
        
    }
};