class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> rooms(n,0);
        priority_queue<int,vector<int>,greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> meetHeap;

        int time=0;

        for(auto& m:meetings){
            long long start=m[0];
            long long end=m[1];
            long long duration=end-start;

            while(!meetHeap.empty() && meetHeap.top().first<=start){
                available.push(meetHeap.top().second);
                meetHeap.pop();
            }
            if(!available.empty()){
                int room=available.top();
                available.pop();
                meetHeap.push({end,room});
                rooms[room]++;
            } else {
                auto [finish,room]=meetHeap.top();
                meetHeap.pop();
                meetHeap.push({finish+duration,room});
                rooms[room]++;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(rooms[i]>rooms[ans]){
                ans=i;
            }
        }
    return ans;
    }
};