#include<bits/stdc++.h>
using namespace std;
int n, k;
int visited[200'004];
queue<int> q;

void bfs(int here, int dep){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    q.push(n);
    visited[n] = 1;
    while(q.size()){
        int here = q.front(); q.pop();
        if(visited[k]) break;

        for(int next : {here + 1, here - 1, here * 2}){
            if(next > 200'000 || next < 0 || visited[next]) continue;
            visited[next] = visited[here] + 1;
            q.push(next);
        }
    }
    cout << visited[k] - 1;
}