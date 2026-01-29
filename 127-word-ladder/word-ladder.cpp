class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        int L=beginWord.size();

        for(string& word:wordList){
            for(int i=0;i<L;i++){
                string pattern=word;
                pattern[i]='*';
                adj[pattern].push_back(word);
            }
        }

        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({beginWord,1});
        visited.insert(beginWord);

        while(!q.empty()){
            auto [word,level]=q.front();
            q.pop();

            for(int i=0;i<L;i++){
                string pattern=word;
                pattern[i]='*';

                for(string &nextWord:adj[pattern]){
                    if(nextWord==endWord) return level+1;

                    if(!visited.count(nextWord)){
                        visited.insert(nextWord);
                        q.push({nextWord,level+1});
                    }
                }
            }
        }
    return 0;
    }
};