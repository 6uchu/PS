#include <bits/stdc++.h>
using namespace std;
int cnt1, cnt2, v1[104][104], v2[104][104], n;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
char c1[104][104], c2[104][104];

void dfs(int y, int x, int v){
    if(v == 1){
        v1[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= n || nx >= n || nx < 0 || ny < 0 || v1[ny][nx]) continue;
            if(c1[ny][nx] == c1[y][x]) dfs(ny, nx, v);
        }
    }else if (v == 2){
        v2[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= n || nx >= n || nx < 0 || ny < 0 || v2[ny][nx]) continue;
            if(c2[ny][nx] == c2[y][x]) dfs(ny, nx, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c1[i][j];
            if(c1[i][j] == 'B') c2[i][j] = 'B';
            else c2[i][j] == 'R';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v1[i][j] == 0){
                dfs(i, j, 1);
                cnt1++;
            }
            if(v2[i][j] == 0){
                dfs(i, j, 2);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2;
    return 0;
}