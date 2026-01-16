#include<bits/stdc++.h>
using namespace std;
int dp[34][34], ret;
/*
해당 인덱스에서의 최대값 
        11
    21       22
31       32       33
*/
int main(){
    int n, k;
    cin >> n >> k;
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
    dp[4][1] = 1; dp[4][2] = 3; dp[4][3] = 3; dp[4][4] = 1;
    
    if(n <= 4){
        cout << dp[n][k];
        return 0;
    }

    for(int i = 5; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            if(i == n && j == k){
                cout << dp[n][k];
                return 0;
            }
        }
    }
}