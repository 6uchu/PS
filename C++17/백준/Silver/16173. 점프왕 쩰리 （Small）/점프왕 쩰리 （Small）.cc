#include <bits/stdc++.h>
using namespace std;
int k, arr[5][5], visited[5][5];
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cin >> arr[i][j];
            if(min(i, j) + arr[i][j] > 2) arr[i][j] = -2;
        }
    }

    q.push({0, 0});
    while(q.size()){
        int y, x; tie(y, x) = q.front();
        if(arr[y][x] == -1) {
            cout << "HaruHaru";
            return 0;
        }
        q.pop();
        
        if(!(arr[y][x] == -2 || y + arr[y][x] > k - 1 || visited[y + arr[y][x]][x])){
            q.push({y + arr[y][x], x});
            visited[y + arr[y][x]][x] = 1;
        }
        if(!(arr[y][x] == -2 || x + arr[y][x] > k - 1 || visited[y][x + arr[y][x]])){
            q.push({y, x + arr[y][x]});
            visited[y][x + arr[y][x]] = 1;
        }
    }

    cout << "Hing";
    return 0;
}  