class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            res.push_back(sum%10);
            carry=sum/10;
        }
        if(carry>0) res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};