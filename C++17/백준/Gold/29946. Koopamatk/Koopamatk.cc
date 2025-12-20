#include<bits/stdc++.h>
using namespace std;
pair<int, int> _from, ret;
char c[104][104];
int n, m, dist[104][104];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void star(pair<int, int> yx){
    auto [y, x] = yx;
    while(dist[y][x] != 0){
        c[y][x] = '*';
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            
            if(dist[ny][nx] == dist[y][x] - 1){
                x = nx;
                y = ny;
                break;
            }
        }
    }
    return;
}

pair<int, int> bfs(pair<int, int> yx){
    q.push(yx);
    dist[yx.first][yx.second] = 0;

    while(!q.empty()){
        auto [y, x] = q.front();
        if(y == 0 || x == 0 || y == n-1 || x == m-1){
            star({y, x});
            return {y, x};
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n || 
                dist[ny][nx] != -1 || c[ny][nx] != '.') continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return {-1, -1};
}

int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof(dist));

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == '@')
                _from = {i, j};
        }
    }
    ret = bfs(_from);
    if(ret.first == -1){
        cout << "-1\n";
    }else{
        cout << dist[ret.first][ret.second] << '\n';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //printf("%2d ", dist[i][j]);
            cout << c[i][j];
        }
        cout << '\n';
    }
}