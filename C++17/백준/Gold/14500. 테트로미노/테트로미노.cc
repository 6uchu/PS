#include <bits/stdc++.h>
using namespace std;
int arr[504][504], visited[504][504], n, m, ret = -1e9;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

void solve(int y, int x, int sum){
    //cout << visited[y][x] << "(" << y << ", " << x << ")" << ",  ";
    sum += arr[y][x];
    if(visited[y][x] == 4){
        //cout << '\n';
        ret = max(sum, ret);
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        solve(ny, nx, sum);
        visited[ny][nx] = 0;
    }
}

void checkT(int y, int x){
    for(int i = 0; i < 4; i++){
        int sum = arr[y][x];
        bool ok = true;
        for(int j = 0; j < 3; j++){
            int d = (i + j) % 4; // <- 구조 절묘함
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m){
                ok = false;
                break;
            }
            sum += arr[ny][nx];
        }
        if(ok) ret = max(ret, sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 1;
            solve(i, j, 0);
            visited[i][j] = 0;
            checkT(i, j);
        }
    }

    cout << ret;
    return 0;
}