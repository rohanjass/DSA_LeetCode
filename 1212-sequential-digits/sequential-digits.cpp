class Solution {
public:
    void func(int i,int path,vector<int>& seq,vector<int>& res,int low,int high){
        if(low<=path && path<=high) res.push_back(path);
        if(i==seq.size()-1) return;
        int newPath=path*10+seq[i+1];
        if(newPath<=high) func(i+1,newPath,seq,res,low,high);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seq={1,2,3,4,5,6,7,8,9};
        vector<int> res;
        for(int i=0;i<9;i++){
            func(i,seq[i],seq,res,low,high);
        }
        sort(res.begin(),res.end());
    return res;
    }
};