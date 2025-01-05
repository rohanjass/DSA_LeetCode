class Solution {
struct TrieNode{
    unordered_map<char,TrieNode*> children;
    string word="";
};
public:
    void insert(TrieNode* root,string& word){
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->children[c]){
                cur->children[c]=new TrieNode();
            }
            cur=cur->children[c];
        }
        cur->word=word;
    }

    void search(vector<vector<char>>& board,TrieNode* node,vector<string>& res,int row , int col,int m,int n){
        if(row<0 || col<0 || row==m || col==n || board[row][col]=='.' || !node->children.count(board[row][col])) return;
        char c=board[row][col];
        TrieNode* nextNode=node->children[c];
        if(!nextNode->word.empty()){
            res.push_back(nextNode->word);
            nextNode->word="";
        }

        board[row][col]='.';

        search(board,nextNode,res,row+1,col,m,n);
        search(board,nextNode,res,row-1,col,m,n);
        search(board,nextNode,res,row,col+1,m,n);
        search(board,nextNode,res,row,col-1,m,n);
        board[row][col]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();
        TrieNode* root=new TrieNode();
        vector<string> res;
        for(string word:words){
            insert(root,word);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                search(board,root,res,i,j,m,n);
            }    
        }
    
    return res;
    }
};