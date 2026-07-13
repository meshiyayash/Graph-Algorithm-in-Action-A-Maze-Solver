class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis[x]=1;

            for(auto i:rooms[x]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                return 0;
            }
        }

        return 1;
    }
};
