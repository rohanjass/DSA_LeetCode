class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({efficiency[i],speed[i]});
        }
        sort(arr.rbegin(),arr.rend());

        priority_queue<int,vector<int>,greater<>> pq;

        long long speedSum=0;
        long long res=0;
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            int eff=arr[i].first;
            int sp=arr[i].second;

            pq.push(sp);
            speedSum+=sp;
            
            if(pq.size()>k){
                speedSum-=pq.top();
                pq.pop();
            }

        res=max(res,speedSum*eff);
        }
    return res%MOD;
    }
};