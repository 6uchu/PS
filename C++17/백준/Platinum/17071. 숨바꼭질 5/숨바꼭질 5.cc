/*
해결 로직
{플루드 필: bfs에서 level 별로 묶아서 층층히 풀이 해야하는 경우}
움직이는 k에 대해 
술래가 먼저 도착하는 경우 + 사전에 도착한 경우를 생각
사전에 도착한 경우 turn번째 일때 
짝수 만큼 차이나는 과거 turn에 방문 했었다면 가능
<- visited에 저장 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, ok, turn = 1;
int visited[2][MAX + 4];
queue<int> q;

int main(){
    cin.tie(NULL);

    cin >> n >> k;
    if(n == k){cout << 0; return 0;}
    q.push(n);
    visited[0][n] = 1;
    while(q.size()){
        k += turn;
        if(k > MAX) break;
        if(visited[turn % 2][k]){ok = true; break;}
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){ //<-플루드 필 key
            int x = q.front(); q.pop();
            for(int nx : {x + 1, x - 1, x * 2}){
                if(nx < 0 || nx > MAX || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if(nx == k){ok = true; break;}
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn;
    else cout << -1;
}