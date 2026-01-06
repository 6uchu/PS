#include<bits/stdc++.h>
using namespace std;
int my, mx, y, x, ny, nx, max_ = -1;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0 , -1, 0};
int visited[26];
char arr[24][24];

void dfs(int y, int x, int dep){
    max_ = max(max_, dep);
    
    for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= my || nx >= mx) continue;
        int next = arr[ny][nx] - 'A';
        if(visited[next] == 0){
            visited[next] = 1;
            dfs(ny, nx, dep + 1);
            visited[next] = 0;
        }
    }
}

int main(){
    cin >> my >> mx;
    for(int i = 0; i < my; i++){
        for(int j = 0; j < mx; j++){
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << max_;
}