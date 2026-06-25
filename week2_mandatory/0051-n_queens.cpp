class Solution {

    bool isSafe(unordered_map<int,int>&q,int row,int col){
        for(auto [key,value] : q){
            if(value==col || (value-key)==(col-row) || (value+key)==(col+row)){
                return false;
            }
        }
        return true;
    }

    void nqueens(int n,int row,vector<string>&board,vector<vector<string>>&ans,unordered_map<int,int>&q){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(q,row,i)){
                board[row][i]='Q';
                q[row]=i;
                nqueens(n,row+1,board,ans,q);
                board[row][i]='.';
                q.erase(row);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        unordered_map<int,int> q;
        
        nqueens(n,0,board,ans,q);
        return ans;
    }
};
