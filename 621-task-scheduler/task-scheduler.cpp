class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char c:tasks){
            count[c-'A']++;
        }
        priority_queue<int>maxH;
        for(int i=0;i<count.size();i++){
            if(count[i]>0) maxH.push(count[i]);
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!maxH.empty() || !q.empty()){
            time++;
            if(maxH.empty()){
                time=q.front().second;
            } else {
                int cnt=maxH.top()-1;
                maxH.pop();
                if(cnt>0) q.push({cnt,time+n});
            }

            if(!q.empty() && q.front().second==time){
                maxH.push(q.front().first);
                q.pop();
            }
        }
    return time;
    }
};