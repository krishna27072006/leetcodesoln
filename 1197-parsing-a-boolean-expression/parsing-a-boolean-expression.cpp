class Solution {
public:
    bool parseBoolExpr(string e) {
        int i=0;
        stack<char>st;
        while(i<e.size()){
            if(e[i]!=')' ){
                if(e[i]!=','){
                st.push(e[i]);
                
                }
            }else{
                vector<char> ch;
                while(st.top()!='('){
                    ch.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                bool next = (ch[0] == 't');
                if(ch.size()==1){
                    if(op=='!'){
                        if(ch[0]=='t'){
                            st.push('f');
                        }else{
                            st.push('t');
                        }
                    }else{
                        st.push(ch[0]);
                    }
                }else{
                    for(int j=1;j<ch.size();++j){
                        bool curr;
                        if(ch[j]=='t'){
                            curr=true;
                        }else{
                            curr=false;
                        }
                        if(op=='|'){
                            next=next||curr;
                        }else{
                            next=next && curr;
                        }
                    }
                    if(next==true){
                        st.push('t');
                    }else{
                        st.push('f');
                    }
                    

                }
                

            }
            i++;

        }
        return st.top()=='t';
    }
};