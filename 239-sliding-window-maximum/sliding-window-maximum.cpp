class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
                //means this element is out of the window
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
                //maintain decreasing order across the curr windwo in dq so, we get max at dq.front()
            }
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
    return res;
    }
};