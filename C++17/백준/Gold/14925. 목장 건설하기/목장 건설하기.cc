#include<bits/stdc++.h>
using namespace std;
int my, mx, k, dp[1004][1004], ret;

int main(){
    cin >> my >> mx;

    
    for(int i = 0; i < my; i++){
        for(int j = 0; j < mx; j++){
            cin >> k;
            if(k == 0){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                    if(dp[i][j] > ret) ret = dp[i][j]; // <- 반례
                    continue;
                }
                int min_ = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(min_, dp[i - 1][j - 1]) + 1;
                if(dp[i][j] > ret) ret = dp[i][j];
            }
        }
    }

    cout << ret;
}
