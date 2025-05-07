class Solution {
public:
   static bool cmp(const vector<int>a,const vector<int>b){
    return a[1]<b[1];
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removeCount=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastInd=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(lastInd>intervals[i][0]){
                removeCount++;
            }
            else lastInd=intervals[i][1];
        }
    return removeCount;
    }
};