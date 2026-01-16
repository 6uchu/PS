#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, cost[14][14], ret = INF;

bool check(int a, int b, int c){
    int visited[14][14];
    memset(visited, 0, sizeof(visited));
    int ay, ax, by, bx, cy, cx;
    int dy[] = {1, 0 , -1, 0}, dx[] = {0, 1, 0, -1};
    pair<int, int> d[3];
    ay = a / n; ax= a % n;
    by = b / n; bx= b % n;
    cy = c / n; cx= c % n;
    d[0] = {ay, ax}; d[1] = {by, bx}; d[2] = {cy, cx}; 
    if(ay == 0 || ax == 0 || by == 0 || bx == 0 || cy == 0 || cx== 0 ) return false;
    if(ay == n - 1 || ax == n - 1 || by == n - 1 || bx == n - 1 || cy == n - 1 || cx== n - 1) return false;

    for(auto cordi : d){
        visited[cordi.first][cordi.second] = 1;
        for(int i = 0; i < 4; i++){
            if(visited[cordi.first + dy[i]][cordi.second + dx[i]]) return false;
            visited[cordi.first + dy[i]][cordi.second + dx[i]] = 1;
        }
    }

    return true;
}

int sumCost(int a){
    int ay, ax;
    ay = a / n; ax= a % n;

    return cost[ay][ax] + cost[ay + 1][ax] + cost[ay - 1][ax] + cost[ay][ax + 1] + cost[ay][ax - 1];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < n * n; i++){
        for(int j = i + 1; j < n * n; j++){
            for(int l = j + 1; l < n * n; l++){
                if(check(i, j, l)){
                    int sum = sumCost(i) + sumCost(j) + sumCost(l);
                    if(sum < ret) {
                        ret = sum;
                    }
                }
            }
        }
    }
    cout << ret;
}
