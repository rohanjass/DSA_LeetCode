class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxH;
        vector<int> count(26,0);
        queue<pair<int,int>>q;//{cnt,time}
        for(char c:tasks){
            count[c-'A']++;
        }
        for(int i:count){
            if(i>0) maxH.push(i);
        }
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


//maxH contain the tasks that we can use imediately based on their ant priority 
// if A is scheduled to be used on time 7 we push it to priority queue on time 6 bcoz on next iteration time 7 will be updated and we can pop it from the PQ and use it
//use of the queue is to schedule the task ; when it will go to the PQ