#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

// 必要な変数
int w,h,n;
vector<int> dx = {0,-1,0,1};
vector<int> dy = {1,0,-1,0};
vector<char> direction = {'E','N','W','S'};
vector<vector<bool>> grid;

vector<vector<int>> bfs(int sx,int sy,int gx,int gy,vector<vector<bool>> visited){
    queue<pair<int,int>> que;
    que.push({sx,sy});
    visited[sx][sy] = true;
    vector<vector<int>> dis(h,vector<int>(w,INF));
    dis[sx][sy] = 0;
    while(!que.empty()){
        auto [x,y] = que.front();que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(!grid[nx][ny] || visited[nx][ny] || dis[nx][ny]!=INF) continue;
            visited[nx][ny] = true;
            dis[nx][ny] = dis[x][y] + 1;
            que.push({nx,ny});
        }
    }
    return dis;
}
int main(){
    cin >> w >> h >> n;
    grid.assign(h,vector<bool>(w,true));
    map<string,pair<int,int>> pos;
    int x,y;
    string s;
    char d;
    int sx = h-1;
    int sy = 1;
    int gx = h-1;
    int gy = w-2;

    // 入れない位置を記録する
    grid[0][0] = grid[0][w-1] = grid[h-1][0] = grid[h-1][w-1] = false;
    for(int i = 2; i <= w-3; i++){
        grid[h-1][i] = false;
    }
    for(int i = 0; i < n; i++){
        cin >> x >> y >> s >> d;
        int pos_x = h-1-y;
        int pos_y = x;
        // 棚の位置は入れない
        grid[pos_x][pos_y] = false;
        for(int j = 0; j < 4; j++){
            if(d == direction[j]){
                int newx = pos_x + dx[j];
                int newy = pos_y + dy[j];
                pos[s] = {newx,newy};
            }
        }
    }
    int q,m;
    cin >> q;
    vector<int> ans;
    while(q--){
        cin >> m;
        string p;
        // 今回はm=1のケースのみを考慮。
        for(int i = 0; i < m; i++){
            cin >> p;
        }
        auto [target_x, target_y] = pos[p];
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        vector<vector<int>> entrance_to_target = bfs(sx,sy,target_x,target_y,visited);
        vector<vector<int>> target_to_exit = bfs(target_x,target_y,gx,gy,visited);
        ans.push_back(entrance_to_target[target_x][target_y]+target_to_exit[gx][gy]);
    }
    for(auto it : ans){
        cout << it << endl;
    }

}