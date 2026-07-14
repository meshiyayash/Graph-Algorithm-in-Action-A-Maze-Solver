class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> pre(n,0);
        vector<vector<int>> neighbors(n);
        for(int i=0;i<prerequisites.size();i++){
            pre[prerequisites[i][0]]++;
            neighbors[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(pre[i]==0){
                q.push(i);
            }
        }

        if(q.empty()){
            return 0;
        }
        int cnt=0;
        while(!q.empty() && pre[q.front()]==0){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto i:neighbors[x]){
                pre[i]--;
                if(pre[i]==0){
                    q.push(i);
                }
            }
        }

        if(cnt == n){
            return 1;
        } else {
            return 0;
        }
    }
};
