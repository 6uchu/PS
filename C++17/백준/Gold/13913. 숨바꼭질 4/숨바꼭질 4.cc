//bfs + trace
#include<bits/stdc++.h>
using namespace std;
const int max_n = 200000; //문제에서 한정된 공간을 다루지 않음
int n, k, x, visited[max_n + 4], prevv[max_n + 4];
vector<int> ret;
queue<int> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    visited[n] = 1; 
    q.push(n);

    while(!q.empty()){
        int flag = 0;
        x = q.front();
        q.pop();
        
        for(int nx : {x + 1, x - 1, x * 2}){
            if(nx < 0 || nx >= max_n) continue;
            if(visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            prevv[nx] = x;
            q.push(nx);
            if(nx == k){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    for(int i = k; i != n; i = prevv[i]){
        ret.push_back(i);
    }
    ret.push_back(n);
    cout << visited[k] - 1 << '\n';
    reverse(ret.begin(), ret.end());
    for(int a : ret) cout << a << ' ';
}