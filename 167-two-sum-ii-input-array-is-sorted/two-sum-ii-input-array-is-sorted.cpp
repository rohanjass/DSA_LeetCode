class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l=0,r=numbers.size()-1;
        while(l<=r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            } else if(sum<target){
                l++;
            } else{
                r--;
            }
        }
    return res;
    }
};