class Solution {
public:
    int minFlips(int A, int B, int C) {
        vector<int> a(30,0);
        vector<int> b(30,0);
        vector<int> c(30,0);
        for (int i=29;i>=0 && A>0;i--) {
           a[i]=A%2;
            A/=2;
        }
        for (int i=29;i>=0 && B>0;i--) {
           b[i]=B%2;
            B/=2;
        }
        for (int i=29;i>=0 && C>0;i--) {
           c[i]=C%2;
            C/=2;
        }
        int ct=0;
        for (int i = 29; i >= 0; --i) {
            if ( (a[i] | b[i]) != c[i] ) {
                if (c[i] == 0) {
                    ct += a[i] + b[i];
                } else {
                    ct++;
                }
            }
        }
        return ct;
        
    }
};