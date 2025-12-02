class Twitter {
public:
    unordered_map<int,set<int>> followMap;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        auto comp=[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        followMap[userId].insert(userId);

        for(int followeeId:followMap[userId]){
            if(tweetMap.count(followeeId) && !tweetMap[followeeId].empty()){
                const vector<pair<int,int>>& tweets=tweetMap[followeeId];
                int ind=tweets.size()-1;
                maxHeap.push({tweets[ind].first,tweets[ind].second,followeeId,ind});
            }
        }

        while(!maxHeap.empty() && res.size()<10){
            vector<int> cur=maxHeap.top();
            maxHeap.pop();
            res.push_back(cur[1]);
            int ind=cur[3];
            if(ind>0){
                const pair<int,int>& tweet=tweetMap[cur[2]][ind-1];
                maxHeap.push({tweet.first,tweet.second,cur[2],ind-1});
            }
        }
        
    return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
           followMap[ followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[ followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */