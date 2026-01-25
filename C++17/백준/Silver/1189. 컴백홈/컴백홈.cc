#include <bits/stdc++.h>
using namespace std;
int r, c, k, ret, 
    dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1}, visited[9][9];
char arr[9][9];


void dfs(int y, int x, int dep){
    if(y == 0 && x == c - 1){
        
        if(dep == k) {
            // for(int i = 0; i < r; i++){
            //     for(int j = 0; j < c; j++){
            //         cout << visited[i][j];
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            ret++;
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
        if(arr[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        //cout << dep << '(' << ny << ',' << nx << ')';
        dfs(ny, nx, dep + 1);
        visited[ny][nx] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c >> k;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 1);

    cout << ret;

    return 0;
}