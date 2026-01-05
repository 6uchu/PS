#include<bits/stdc++.h>
using namespace std;
bool flag = true;
int visited1[1504][1504], waterv[1504][1504], y, x, ny, nx, my, mx, ret;
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
char arr[1504][1504];
pair<int, int> swan, here;
queue<pair<int, int>> q, tempq, waterq;

void qClear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void iceMelting(){
    while(waterq.size()){
        tie(y, x) = waterq.front(); waterq.pop();
        waterv[y][x] = 1;
        for(int i = 0; i < 4; i++){
            ny = y + dy[i]; nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= my || nx >= mx || waterv[ny][nx] == 1) continue;
            waterv[ny][nx] = 1;
            if(arr[ny][nx] == 'X'){
                tempq.push({ny, nx});
                arr[ny][nx] = '.';
            }
        }
    }
    while(tempq.size()){
        waterq.push(tempq.front());
        tempq.pop();
    }
}

void swanMove(){
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i]; nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= my || nx >= mx || visited1[ny][nx] == 1) continue;
            visited1[ny][nx] = 1;
            if(arr[ny][nx] == 'L') {flag = false; return;}
            else if(arr[ny][nx] == 'X') {tempq.push({ny, nx});}
            else q.push({ny, nx});
        }
    }
    while(tempq.size()){
        q.push(tempq.front());
        tempq.pop();
    }
}

int main(){
    cin >> my >> mx;

    for(int i = 0; i < my; i++){
        for(int j = 0; j < mx; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'L') swan = {i, j};
            if(arr[i][j] != 'X') waterq.push({i, j});
        }
    }
    visited1[swan.first][swan.second] = 1;
    q.push(swan);
    while(true){
        swanMove();
        if(!flag) break;
        iceMelting();
        ret++;
    }
    cout << ret;
}