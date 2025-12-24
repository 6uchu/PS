#include<bits/stdc++.h>
using namespace std;

int n, k, visited[100004], cnt[100004]; //n이 움직임
//visited: level
//cnt: 최소 level 일 때 해당 노드 방문 횟수
int ret = 987654321, mincnt;
queue<int> q;
int level;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    visited[n] = 1; // 초기 정점이 0이면 무조건 예외 처리 해줘야함
    cnt[n] = 1;
    q.push(n);

    while(q.size()){
        int here = q.front(); 
        q.pop();
        for(int next : {here - 1, here + 1, here * 2}){
            if(0 <= next && next <= 100000){
                if(!visited[next]){// 방문 안 했으면
                    q.push(next);
                    visited[next] = visited[here] + 1;
                    cnt[next] += cnt[here];
                }else if(visited[next] == visited[here] + 1){// 같은 레벨이면 방문 횟수에 더함
                    cnt[next] += cnt[here];
                }
            }
        }        
    }
    cout << visited[k] - 1 << '\n'; //시간이면 -1
    cout << cnt[k] << '\n';
}