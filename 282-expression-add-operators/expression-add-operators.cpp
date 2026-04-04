class Solution {
public:
    vector<string> res;
    void func(int ind,string& num,int target,long current,long prev,string path){
        if(ind==num.size()){
            if(current==target) res.push_back(path);
        return;
        }
        
        for(int i=ind;i<num.size();i++){
            if(i!=ind && num[ind]=='0') break;

            string currentStr=num.substr(ind,i-ind+1);
            long cur=stol(currentStr);

            if(ind==0){
                func(i+1,num,target,cur,cur,currentStr);
            } else {
                func(i+1,num,target,current+cur,cur,path+"+"+currentStr);
                func(i+1,num,target,current-cur,-cur,path+"-"+currentStr);
                func(i+1,num,target,current-prev+(prev*cur),prev*cur,path+"*"+currentStr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        func(0,num,target,0,0,"");
    return res;
    }
};