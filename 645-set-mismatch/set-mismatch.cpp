class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n+1,0);
        for(int num:nums){
            count[num]++;
        }
        int dup=-1,missing=-1;
        for(int i=0;i<=nums.size();i++){
            if(count[i]==2) dup=i;
            else if(count[i]==0) missing=i;
        }
    return {dup,missing};
    }
};