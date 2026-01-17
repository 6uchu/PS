#include <bits/stdc++.h>
using namespace std;
int arr[2200][2200], n, one, zero, mone;

void cnt(int here){
    if(here == 1) one++;
    else if(here == 0) zero++;
    else mone++;
}

void solve(int y, int x, int sizee){
    if(sizee == 1) { cnt(arr[y][x]); return; }

    int start = arr[y][x];

    for(int i = 0; i < sizee; i++){
        for(int j = 0; j < sizee; j++){
            int ny = y + i, nx = x + j;
            if(start != arr[ny][nx]){
                int splited = sizee / 3;
                solve(y, x, splited); solve(y, x + splited, splited); solve(y, x + 2 * splited, splited);
                solve(y + splited, x, splited); solve(y + splited, x + splited, splited); solve(y + splited, x + 2 * splited, splited);
                solve(y + splited * 2, x, splited); solve(y + 2 * splited, x + splited, splited); solve(y + 2 * splited, x + 2 * splited, splited); 
                return;
            }
        }
    }
    cnt(start);
    return;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    solve(0, 0, n);

    cout << mone << '\n';
    cout << zero << '\n';
    cout << one << '\n';
}