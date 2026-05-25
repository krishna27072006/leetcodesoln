class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        int start=ni[0];
        int end=ni[1];
        int si=-1;
        int fi=-1;
        int n=in.size();

        for(int i=0;i<in.size();++i){
            if(in[i][0]<=start && in[i][1]>=start){
                start=in[i][0];
                si=i;
            }
            else if(in[i][0]>=start && in[i][0]<=end){
                if(si==-1) si=i;
                end=max(end,in[i][1]);
            }
        }
        for(int i=0;i<in.size();++i){
            if(in[i][0]<=end && in[i][1]>=end){
                end=in[i][1];
                fi=i;
            }
            else if(in[i][1]>=start && in[i][0]<=end){
                fi=i;
                start=min(start,in[i][0]);
            }
        }
        if(si!=-1 && fi!=-1){
            in.erase(in.begin()+si,in.begin()+fi+1);
        } 
        else if(si==-1 && fi!=-1){
            in.erase(in.begin()+0,in.begin()+fi+1);
        }
        else if(si!=-1 && fi==-1){
            in.erase(in.begin()+si,in.begin()+n);
        }
        in.push_back({start,end});
        sort(in.begin(),in.end());

        return in;
    }
};