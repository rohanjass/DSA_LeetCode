class Solution {
public:
    bool dfs(int ind ,int r ,int c ,vector<vector<char>>& board, string word){
        if(ind==word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[ind] || board[r][c]=='!') return false;
        char ch=board[r][c];
        board[r][c]='!';
        bool left=dfs(ind+1,r+1,c,board,word);
        bool right=dfs(ind+1,r-1,c,board,word);
        bool u=dfs(ind+1,r,c+1,board,word);
        bool d=dfs(ind+1,r,c-1,board,word);
        board[r][c]=ch;
    return left||right||u||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(0,i,j,board,word)) return true;
            }
        }
    return false;
    }
};