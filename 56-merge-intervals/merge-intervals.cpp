class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        int lastInd=0;
        for(int i=1;i<n;i++){
            if(res[lastInd][1]>=intervals[i][0]){
                res[lastInd][1]=max(res[lastInd][1],intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                lastInd++;
            }
        }
    return res;
    }
};