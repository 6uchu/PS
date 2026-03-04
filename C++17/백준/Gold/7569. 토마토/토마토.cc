#include <bits/stdc++.h>
using namespace std;
int n, m, h, box[104][104][104], cnt;
int dz[] = {1, 0, 0, -1, 0, 0}, dy[] = {0, 1, 0, 0, -1, 0}, dx[] = {0, 0, 1, 0, 0, -1};
struct tomato
{
    int z, y, x;
};

queue<tomato> q;


void dfs(){
    while(q.empty()){

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >> box[i][j][k];

                if(box[i][j][k] == 1){
                    q.push({i, j, k});
                }
            }
        }
    }

    while(!q.empty()){
        tomato here = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int nz = here.z + dz[i], ny = here.y + dy[i], nx = here.x + dx[i];
            if(nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= m || nx >= n) continue;
            if(box[nz][ny][nx] != 0) continue;
            box[nz][ny][nx] = box[here.z][here.y][here.x] + 1;
            q.push({nz, ny, nx});
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                if(box[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                cnt = max(cnt, box[i][j][k]);
            }
        }
    }

    cout << cnt - 1;
    return 0;
}