//좌상단 (1,1) 두 자석의 행, 렬 모두의 거리가 D보다 가까울 때 아웃 
//1000000
#include<bits/stdc++.h>
using namespace std;
int n, d, arr[1004][1004], summ[1004][1004], ret = 1e9;
vector<pair<int, int>> zeros;
pair<int, int> rett;

void solve(int y, int x){
    int sy, ey, sx, ex;
    sy = max(1, y - d) - 1; ey = min(n, y + d);
    sx = max(1, x - d) - 1; ex = min(n, x + d);
    int sum = 0;

    sum = summ[ey][ex] - summ[sy][ex] - summ[ey][sx] + summ[sy][sx]; 

    if(sum < ret) { rett = {y, x}; ret = sum; }
}

void sum(int y, int x){
    summ[y][x] += summ[y - 1][x] + summ[y][x - 1] - summ[y - 1][x - 1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            summ[i][j] = arr[i][j];
            sum(i, j);
            if(arr[i][j] == 0) zeros.push_back({i, j});
        }
    }

    for(auto a : zeros){
        solve(a.first, a.second);
        if(ret == 0) break;
    }
    cout << rett.first << ' ' << rett.second << '\n';
    if(ret)
        cout << ret;
}