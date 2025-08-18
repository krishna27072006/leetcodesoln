class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        string s="123456789";
        for(int i=1;i<=9;++i){
            for(int j=1;j<=9-i+1;j++){
                string p="";
                for(int k=j;k<j+i;++k){
                    p+=s[k-1];
                }
                int n=stoi(p);
                if (n >= low && n <= high) {         
                    v.push_back(n);
                }
            }
        }
        return v;


    }
};