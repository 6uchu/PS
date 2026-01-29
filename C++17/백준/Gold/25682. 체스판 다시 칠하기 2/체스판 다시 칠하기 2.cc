#include <bits/stdc++.h>
using namespace std;
int n, m, k, ret = 1e9;
char arr[2004][2004];

int white[2004][2004], black[2004][2004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            
            white[i][j] = white[i][j - 1] + white[i - 1][j] - white[i - 1][j - 1];
            black[i][j] = black[i][j - 1] + black[i - 1][j] - black[i - 1][j - 1];
            if(arr[i][j] == 'W'){
                if((i + j) & 1) white[i][j] += 1;
                else black[i][j] += 1;
            }else{
                if((i + j) & 1) black[i][j] += 1;
                else white[i][j] += 1;
            }
        }
    }

    for(int i = k; i <= n; i++){
        for(int j = k; j <= m; j++){
            int w = white[i][j] - white[i][j - k] - white[i - k][j] + white[i - k][j - k];
            int b = black[i][j] - black[i][j - k] - black[i - k][j] + black[i - k][j - k];
            ret = min(ret, w);
            ret = min(ret, b);
        }
    }

    cout << ret;

    return 0;
}