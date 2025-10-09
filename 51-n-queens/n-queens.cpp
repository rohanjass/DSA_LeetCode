class Solution {
public:
    void def(int row,int n,vector<string>&board,vector<int>& col,vector<int>&lowerDia,vector<int>&upperDia ,vector<vector<string>>& res){
        if(row==n){
            res.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(col[i]==0 && lowerDia[n-1+row-i]==0 && upperDia[row+i]==0){
                board[row][i]='Q';
                col[i]=1;
                lowerDia[n-1+row-i]=1;
                upperDia[row+i]=1;

                def(row+1,n,board,col,lowerDia,upperDia,res);

                board[row][i]='.';
                col[i]=0;
                lowerDia[n-1+row-i]=0;
                upperDia[row+i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> col(n,0),lowerDia(2*n-1,0),upperDia(2*n-1,0);
        def(0,n,board,col,lowerDia,upperDia,res);
    return res;
    }
};