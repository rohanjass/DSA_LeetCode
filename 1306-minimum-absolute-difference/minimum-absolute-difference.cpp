class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int l=0,r=1;
        vector<vector<int>> res;
        int minDiff=INT_MAX;
        while(r<arr.size()){
            int currDiff=arr[r]-arr[l];
            if(currDiff<minDiff){
                minDiff=currDiff;
                res.clear();
                res.push_back({arr[l],arr[r]});
            } else if(currDiff==minDiff){
                res.push_back({arr[l],arr[r]});
            }
            r++;
            l++;
        }
    return res;
    }
};