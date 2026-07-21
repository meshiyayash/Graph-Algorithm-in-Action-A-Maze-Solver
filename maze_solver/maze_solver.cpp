#include<bits/stdc++.h>
using namespace std;


struct Grid { 
    int R, C;
    vector<string> cells; 
};

struct Result {
    int cost;                                  // total steps or total weight
    vector<pair<int,int>> path;                // cells in order
    int expanded;                              // cells visited by the search
};


// Shared neighbour helper (no copy-paste across algorithms):
vector<pair<int,int>> neighbours(const Grid& g, int r, int c){
    vector<pair<int,int>> n;
    vector<int>dir = {0,1,0,-1,0};

    for(int i=0;i<4;i++){
        int x=r+dir[i];
        int y=c+dir[i+1];
        if(x>=0 && x<g.R && y>=0 && y<g.C && g.cells[x][y]!='#'){
            n.push_back({x,y});
        }
    }

    return n;
}

// Single-pair shortest path — implement all four:
Result bfs      (const Grid& g, pair<int,int> s, pair<int,int> t){
    Result search;
    search.cost=0;

    vector<vector<bool>> vis(g.R,vector<bool>(g.C,false));
    queue<pair<int,int>>q;
    q.push(s);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            if(q.front()==t){
                // cout << "hit\n";
                return search;
            }
            int i=q.front().first;
            int j=q.front().second;
            vis[i][j]=true;
            q.pop();

            for(auto n:neighbours(g,i,j)){
                if(!vis[n.first][n.second]){
                    vis[n.first][n.second]=true;
                    q.push(n);
                }
            }
        }
        search.cost++;
    }

    return search;
}


// Result dfsPath  (const Grid& g, pair<int,int> s, pair<int,int> t);
Result dijkstra (const Grid& g, pair<int,int> s, pair<int,int> t);
Result astar    (const Grid& g, pair<int,int> s, pair<int,int> t);

void shortest(const vector<vector<int>>& dist,vector<int>&indx,int&cur_cost,int &best,vector<bool>&vis,vector<int>& outOrder){
// base case ---> if i have visited all the index from start then I should go to the goal
    if(indx.size() == vis.size()){
        cur_cost+=dist[indx.back()][dist.size()-1];
        indx.push_back(dist.size()-1);
        if(cur_cost<best){
            best=cur_cost;
            outOrder=indx;
        }
        indx.pop_back();
        cur_cost-=dist[indx.back()][dist.size()-1];
        return;
    }

// Pruning step ---> IF at any moment my current distance is greater than best I should avoid that path
    if(cur_cost>=best){
        return;
    }
// Recursively visiting each coin and finding minimum cost/distance
    for(int i=1;i+1<=vis.size();i++){
        if(vis[i]){
            continue;
        }

        cur_cost+=dist[indx.back()][i];
        vis[i]=true;
        indx.push_back(i);
        shortest(dist,indx,cur_cost,best,vis,outOrder);

        //backtracing
        indx.pop_back();
        cur_cost-=dist[indx.back()][i];
        vis[i]=false;
    }
}

// Coin-order backtracking:
int bestOrder(const vector<vector<int>>& dist,int startIdx, int goalIdx, vector<int>& outOrder){
    int best=INT_MAX ,cur_cost=0;

    vector<bool> vis(dist.size()-1,false);
    vis[0]=true;

    vector<int> indx;
    indx.push_back(0);
    shortest(dist,indx,cur_cost,best,vis,outOrder);
    
    return best;
}



int main(){

// Initialising grid and taking input    
    Grid g;
    pair<int,int> start,goal;

    cin >> g.R >> g.C;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;

// storing the graph 

    for(int i=0;i<g.R;i++){
        string s;
        cin >> s;
        g.cells.push_back(s);
    }

// Storing the key points
    vector<pair<int,int >> keypoints;
    int total_keypoints;
    keypoints.push_back(start);

    for(int i=0;i<g.R;i++){
        for(int j=0;j<g.C;j++){
            if(g.cells[i][j]=='c'){
                keypoints.push_back({i,j});
            }
        }
    }

    keypoints.push_back(goal);
    total_keypoints=keypoints.size();
// K+2 * K+2 matrix for storing min distance between each key point
    vector<vector<int>> key_points_distance(total_keypoints,vector<int>(total_keypoints,0));

    for(int i=0;i<total_keypoints;i++){
        for(int j=i;j<total_keypoints;j++){
            key_points_distance[i][j]=bfs(g,keypoints[i],keypoints[j]).cost;
            key_points_distance[j][i]=key_points_distance[i][j];
        }
    }

// Finding best path for non weighted graphs
    vector <int> non_weighted_path;
    int non_weighted_path_length=bestOrder(key_points_distance,0,total_keypoints-1,non_weighted_path);

    cout << non_weighted_path_length << endl;
    return 0;
}



