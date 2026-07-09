class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&vis){
        if(i<0||j<0|| i>=board.size() || j>=board[0].size() || board[i][j]=='X' || vis[i][j] ){
            return;
        }

        vis[i][j]=1;

        dfs(i+1,j,board,vis);
        dfs(i-1,j,board,vis);
        dfs(i,j-1,board,vis);
        dfs(i,j+1,board,vis);
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(),vector<bool> (board[0].size(),false));

        for(int j=0;j<board[0].size();j++){
            dfs(0,j,board,vis);
            dfs(board.size()-1,j,board,vis);
        }

        for(int i=0;i<board.size();i++){
            dfs(i,0,board,vis);
            dfs(i,board[0].size()-1,board,vis);
        }

        for(int i=1;i+1<board.size();i++){
            for(int j=1;j+1<board[0].size();j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        
    }
};
