class Solution {
public:
    
    int sumNum(int num){
        int sum=0;
        while(num>0){
            int n=num%10;
            sum+=n;
            num=num/10;
        }
    return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=1e9;
        for(int n:nums){
            int sum=sumNum(n);
            mini=min(mini,sum);
        }
    return mini;
    }
};