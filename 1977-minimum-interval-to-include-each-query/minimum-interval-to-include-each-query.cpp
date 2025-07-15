class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        vector<int> res(queries.size(),-1);
        int i=0;
        for(auto [query, ind ]:q){
            while(i<intervals.size() && intervals[i][0]<=query){
                int l=intervals[i][0];
                int r=intervals[i][1];
                int size=r-l+1;
                if(r>=query){
                    minH.push({size,r});
                }
             ++i;
            }
            while(!minH.empty() && minH.top().second<query){
                minH.pop();
            }
            if(!minH.empty()){
                res[ind]=minH.top().first;
            }
        }
    return res;
    }
};