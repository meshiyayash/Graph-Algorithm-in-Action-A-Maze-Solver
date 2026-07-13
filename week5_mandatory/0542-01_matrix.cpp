class Solution {
public:
    int m,n;
    vector<vector<int>> ans;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        ans=vector<vector<int>>(m,vector<int>(n,1e6));
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int d=0;
        vector<int> dir={0,1,0,-1,0};
        while(!q.empty()){
            int size=q.size();
            int i,j;
            for(int p=0;p<size;p++){
                tie(i,j)=q.front();
                ans[i][j]=d;
                for(int k=0;k<4;k++){
                    int x=i+dir[k];
                    int y=j+dir[k+1];

                    if(x<m && x>=0 && y<n && y>=0 && !vis[x][y]){
                        q.push({x,y});
                        vis[x][y]=1;
                    }
                }
                q.pop();
            }
            d++;
        }

        return ans;
    }
};
