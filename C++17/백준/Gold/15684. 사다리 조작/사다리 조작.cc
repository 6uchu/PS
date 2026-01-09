#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, h, visited[34][14], ret = INF;
//visited[a][b]: a는 세로번째 줄을 의미 1부터 시작, b는 층을 의미 1부터 시작
//해당 위치가 1 이라면 우측으로 사다리가 뻣어 있는거임
//n: 세로 선
//h: 층
//m: 주어진 가로선

bool check(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt); return;
    }
    for(int i = here; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main(){
    cin >> n >> m >> h;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        visited[a][b] = 1;
    }

    go(1, 0);

    if(ret != INF) cout << ret;
    else cout << -1;
}