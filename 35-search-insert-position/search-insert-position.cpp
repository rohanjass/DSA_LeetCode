class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
       int low=0,high=arr.size()-1;
       int mid=0;
       int ans=arr.size();
       while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=target){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }

       }
       return ans;
    }
};