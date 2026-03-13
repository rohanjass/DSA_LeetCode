class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size(),maxi=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minH;
        for(int i=0;i<n;i++){
            int val=nums[i][0];
            minH.push({val,i,0});
            maxi=max(maxi,val);
        }

        int start=0,end=INT_MAX;
        while(true){
            auto curr=minH.top();
            minH.pop();
            int mini=curr[0];
            int row=curr[1];
            int col=curr[2];

            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }

            if(col+1==nums[row].size()) break;
            int next=nums[row][col+1];
            minH.push({next,row,col+1});
            maxi=max(maxi,next);
        }
    return {start,end};
    }
};