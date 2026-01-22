#include<bits/stdc++.h>
using namespace std;
int n, m, mnum, cnt, ny, nx;
int a[10][10], acopy[10][10];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int y, int x){
    int visited[10][10] = {0, };
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || 
            visited[ny][nx] == 1 || acopy[ny][nx] != 0)
                continue;
        acopy[ny][nx] = 2;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

void wall(int w1, int w2, int w3){
    memcpy(acopy, a, sizeof(a));
    acopy[w1 / m][w1 % m] = 1;
    acopy[w2 / m][w2 % m] = 1;
    acopy[w3 / m][w3 % m] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(acopy[i][j] == 2)
                dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(acopy[i][j] == 0)
                cnt++;
        }
    }
    return;
}

void print(int b, int c, int d){
    cout << cnt << b << c << d << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << acopy[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n * m; i++){
        for(int j = i + 1; j < n * m; j++){
            for(int l = j + 1; l < n * m; l++){
                if(a[i / m][i % m] != 0 || a[j / m][j % m] != 0 || a[l / m][l % m] != 0) continue;
                cnt = 0;
                wall(i, j, l);
                mnum = max(cnt, mnum);
                //print(i, j, l);
            }
        }
    }
    cout << mnum;
}