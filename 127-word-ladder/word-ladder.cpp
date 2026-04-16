class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        int L=beginWord.size();

        for(string& s:wordList){
            for(int i=0;i<L;i++){
                string pattern=s;
                pattern[i]='*';
                adj[pattern].push_back(s);
            }
        }

        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited.insert(beginWord);

        while(!q.empty()){
            auto cur=q.front();
            q.pop();

            string word=cur.first;
            int level=cur.second;
        
            for(int i=0;i<L;i++){
                string pattern=word;
                pattern[i]='*';
                for(auto& N:adj[pattern]){
                    if(N==endWord) return level+1;

                    if(visited.count(N))continue;

                    visited.insert(N);
                    q.push({N,level+1});
                }
            }
        }
    return 0;
    }
};