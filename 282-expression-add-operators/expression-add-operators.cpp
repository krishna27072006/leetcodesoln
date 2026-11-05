class Solution{
public:
    void f(vector<string>&ans,string&num,string path,int index,long long value,long long last,int target){
        if(index==num.size()){
            if(value==target) ans.push_back(path);
            return;
        }
        for(int j=index;j<num.size();j++){
            if(j>index&&num[index]=='0') break;
            string str=num.substr(index,j-index+1);
            long long curr=stoll(str);
            if(index==0){
                f(ans,num,path+str,j+1,curr,curr,target);
            }
            else{
                f(ans,num,path+"+"+str,j+1,value+curr,curr,target);
                f(ans,num,path+"-"+str,j+1,value-curr,-curr,target);
                f(ans,num,path+"*"+str,j+1,value-last+last*curr,last*curr,target);
            }
        }
    }
    vector<string> addOperators(string num,int target){
        vector<string>ans;
        f(ans,num,"",0,0,0,target);
        return ans;
    }
};