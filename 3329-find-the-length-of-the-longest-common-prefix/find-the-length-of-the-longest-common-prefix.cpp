class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        for(int num:arr1){
            set.insert(num);
            while(num>0){
                num=num/10;
                set.insert(num);
            }
        }
        int maxNum=0;
        for(int n:arr2){
            if(set.count(n)) maxNum=max(maxNum,n);
            while(n>0){
                n=n/10;
                if(set.count(n)) maxNum=max(maxNum,n);    
            }
        }
        int len=0;
        while(maxNum>0){
            len++;
            maxNum=maxNum/10;
        }
    return len;  
    }
};