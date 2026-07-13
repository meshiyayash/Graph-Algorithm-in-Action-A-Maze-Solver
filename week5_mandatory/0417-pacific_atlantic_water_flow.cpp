class Solution {
public:
    int m,n;
    vector<vector<int>> ans;
    vector<vector<bool>> at,pa;
    queue<pair<int,int>> q;
    void bfs(int i,int j,vector<vector<bool>>&a , vector<vector<int>>&heights){
        q.push({i,j});

        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            if(!a[i][j]){
                a[i][j]=1;
                
                if(i+1<m && heights[i+1][j] >= heights[i][j]) q.push({i+1,j});
                if(i-1>=0 && heights[i-1][j] >= heights[i][j]) q.push({i-1,j});
                if(j+1<n && heights[i][j+1] >= heights[i][j]) q.push({i,j+1});
                if(j-1>=0 && heights[i][j-1] >= heights[i][j]) q.push({i,j-1});
            }

        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        at = pa = vector<vector<bool>>(m,vector<bool>(n,false));

        for(int i=0;i<m;i++) {
            bfs(i,n-1,at,heights);
            bfs(i,0,pa,heights);
        }

        for(int i=0;i<n;i++){
            bfs(0,i,pa,heights);
            bfs(m-1,i,at,heights);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(at[i][j] && pa[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
};
