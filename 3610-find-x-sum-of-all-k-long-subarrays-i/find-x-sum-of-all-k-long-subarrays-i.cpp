class Solution {
public:
    int xSum(int start,int end,vector<int>& nums,int x){
        unordered_map<int,int> freq;
        for(int i=start;i<=end;i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>>arr;
        for(auto p:freq){
            arr.push_back({p.first,p.second});
        }

        sort(arr.begin(),arr.end(),[&](pair<int,int> a,pair<int,int>b){
            if(a.second==b.second) return a.first>b.first;
            return a.second>b.second;
        });

        int sum=0;
        int count=0;
        for(auto it:arr){
            sum+=it.second*it.first;
            count++;
            if(count==x) break;
        }
    return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            ans.push_back(xSum(i,i+k-1,nums,x));
        }
    return ans;
    }
};