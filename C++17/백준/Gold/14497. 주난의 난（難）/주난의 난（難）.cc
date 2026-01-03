//#을 찾는게 목적이고 1인 부분에서 탐색을 한번 멈춤
//bfs를 시작하는 횟수를 출력
//멈춘 지점을 추가적인 큐에 저장 했다가 bfs용 큐에 전달 후 다시 bfs 시작
#include<bits/stdc++.h>
using namespace std;
int visited[304][304], y, x, sy, sx, gy, gx, ny, nx, ret;
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
char arr[304][304];
queue<pair<int, int>> q, qq;

int main(){
    int my, mx; cin >> my >> mx;
    cin >> sy >> sx;
    cin >> gy >> gx;
   
    for(int i = 1; i <= my; i++)
        for(int j = 1; j <= mx; j++)
            cin >> arr[i][j];
    
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(visited[gy][gx] != 1){
        ret++;
        while(qq.size()){
            q.push(qq.front());
            qq.pop();
        }
        while(q.size()){
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                ny = y + dy[i]; nx = x + dx[i];
                if(ny < 1 || nx < 1 || ny > my || nx > mx || visited[ny][nx] == 1) continue;
                visited[ny][nx] = 1;
                if(arr[ny][nx] == '1'){
                    qq.push({ny, nx});
                    continue;
                }else if(arr[ny][nx] == '#') break;
                else q.push({ny, nx});
            }
        }
    }
    cout << ret;
}