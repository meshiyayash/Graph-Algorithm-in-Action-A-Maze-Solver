class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        int ans=0;

        vector<vector<bool>> vis(m,vector<bool> (n,false));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            if(i+1<m && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},t+1});
                vis[i+1][j]=1;
            }

            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},t+1});
                vis[i-1][j]=1;
            }
            if(j+1<n && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},t+1});
                vis[i][j+1]=1;
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},t+1});
                vis[i][j-1]=1;
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }

};
