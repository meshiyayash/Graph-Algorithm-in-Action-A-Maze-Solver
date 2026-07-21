#include<iostream>
#include<vector>
#include<string>
#include <queue>
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


Result dfsPath  (const Grid& g, pair<int,int> s, pair<int,int> t);
Result dijkstra (const Grid& g, pair<int,int> s, pair<int,int> t);
Result astar    (const Grid& g, pair<int,int> s, pair<int,int> t);

// Coin-order backtracking:
int bestOrder(const vector<vector<int>>& dist,
              int startIdx, int goalIdx,
              vector<int>& outOrder);



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
    keypoints.push_back(start);

    for(int i=0;i<g.R;i++){
        for(int j=0;j<g.C;j++){
            if(g.cells[i][j]=='c'){
                keypoints.push_back({i,j});
            }
        }
    }

    keypoints.push_back(goal);

// K+2 * K+2 matrix for storing min distance between each key point
    vector<vector<int>> key_points_distance(keypoints.size(),vector<int>(keypoints.size(),0));

    for(int i=0;i<keypoints.size();i++){
        for(int j=i;j<keypoints.size();j++){
            key_points_distance[i][j]=bfs(g,keypoints[i],keypoints[j]).cost;
            key_points_distance[j][i]=key_points_distance[i][j];
        }
    }


    return 0;
}



