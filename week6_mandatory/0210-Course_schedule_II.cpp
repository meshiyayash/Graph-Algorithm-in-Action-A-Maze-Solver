class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(n);
        vector<int> pre(n,0);
        vector<int> ans;
        int count=0;
        queue<int>q;

        for(auto p : prerequisites){
            neighbors[p[1]].push_back(p[0]);
            pre[p[0]]++;
        }

        for(int i=0;i<n;i++){
            if(pre[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            ans.push_back(x);
            q.pop();

            for(auto i:neighbors[x]){
                pre[i]--;
                if(pre[i]==0){
                    q.push(i);
                }
            }
            count++;
        }

        if(count != n){
            return vector<int> {};
        } else {
            return ans;
        }
    }
};
