#include<bits/stdc++.h>
using namespace std;
int n, l, r, ret, cnt;
int a[54][54], visited[54][54];
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
bool _move = true;
vector<vector<pair<int, int>>> units;
vector<pair<int, int>> unit;
queue<pair<int, int>> q;

void go(const vector<pair<int, int>> unit){
    int sum = 0, avg;

    for(auto [y, x] : unit){
        sum += a[y][x];
    }
    avg = sum / size(unit);

    for(auto [y, x] : unit){
        a[y][x] = avg;
    }
}

void bfs(int yy, int xx){
    unit.clear();
    int sum = 0, gap;
    visited[yy][xx] = 1;
    q.push({yy, xx}); unit.push_back({yy, xx});
    
    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
            

            gap = abs(a[y][x] - a[ny][nx]);
            if(l <= gap && gap <= r){
                visited[ny][nx] = 1;
                _move = true;
                q.push({ny, nx});
                unit.push_back({ny, nx});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    while(_move){
        memset(visited, 0, sizeof(visited)); units.clear();
        _move = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]) {
                    bfs(i, j);
                    if(unit.size() > 1) units.push_back(unit);
                }
            }
        }
        for(auto &vec : units){
            go(vec);
        }
        if(_move) ret++;
    }

    cout << ret;
}