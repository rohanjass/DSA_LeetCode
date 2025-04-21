class Solution {
public:
    bool dfs(int ind,int i,int j,vector<vector<char>>& board,string word){
        if(ind==word.size()) return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[ind] || board[i][j]=='!') return false;
        char c=board[i][j];
        board[i][j]='!';
        bool left=dfs(ind+1,i,j-1,board,word);
        bool right=dfs(ind+1,i,j+1,board,word);
        bool upper=dfs(ind+1,i-1,j,board,word);
        bool bottom=dfs(ind+1,i+1,j,board,word);
        board[i][j]=c;
    return left||right||upper||bottom;
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