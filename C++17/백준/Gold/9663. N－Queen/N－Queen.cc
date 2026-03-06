#include <bits/stdc++.h>
using namespace std;
int l[34], r[34], n, col[20], cnt;

void dfs(int row){
    if(row == n) {cnt++; return;}

    for(int i = 0; i < n; i++){
        if(l[i + row] == 1 || r[i - row + n] == 1 || col[i] == 1) continue;

        l[i + row] = r[i - row + n] = col[i] = 1;
        dfs(row + 1);
        l[i + row] = r[i - row + n] = col[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    dfs(0);

    cout << cnt;
    
    return 0;
}