#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char mp[1004][1004];
int mpJH[1004][1004], mpF[1004][1004], dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1}, x, y, nx, ny;
pair<int, int> JH;
queue<pair<int, int>> q;
int r, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&mpF[0][0], &mpF[0][0] + 1004 * 1004, INF);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'J') JH = pair(i, j);
            if(mp[i][j] == 'F'){
                mpF[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    //불 bfs 만들기~
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(mp[ny][nx] == '#' || mpF[ny][nx] != INF) continue;
            mpF[ny][nx] = mpF[y][x] + 1;
            q.push({ny, nx});
        }
    }

    int ret = 0;
    tie(y, x) = JH;
    mpJH[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        if(y == 0 || x == c - 1 || y == r - 1 || x == 0){
            ret = mpJH[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(mp[ny][nx] == '#' || mpF[ny][nx] <= mpJH[y][x] + 1 || mpJH[ny][nx] != 0) continue;
            mpJH[ny][nx] = mpJH[y][x] + 1;
            
            q.push({ny, nx});
        }
    }

    (ret != 0) ? cout << ret << '\n' : cout << "IMPOSSIBLE \n";
}