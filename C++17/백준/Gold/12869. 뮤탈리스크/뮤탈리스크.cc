#include<bits/stdc++.h>
using namespace std;

int hp[3], n, visited[64][64][64];
int per[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};
struct A{
    int a, b, c;
};
queue<A> q;

int bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, a - per[i][0]);// <- 꿀팁, 인덱싱 오류 방지
            int nb = max(0, b - per[i][1]);
            int nc = max(0, c - per[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }

    return visited[0][0][0] - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> hp[i];
    }

    cout << bfs(hp[0], hp[1], hp[2]);
}