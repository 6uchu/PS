#include<bits/stdc++.h>
using namespace std;
int dp[504][504], ret;
/*
해당 인덱스에서의 최대값 
        11
    21       22
31       32       33
*/
int main(){
    int n, a = 2;
    cin >> n;
    cin >> dp[1][1];
    
    for(;a <= n; a++){
        for(int i = 1; i <= a; i++){
            int num;
            cin >> num;
            if(i == 1){
                dp[a][i] = dp[a - 1][i] + num;
            }else if(i == a){
                dp[a][i] = dp[a - 1][i - 1] + num;
            }else{
                dp[a][i] = max(dp[a - 1][i - 1], dp[a - 1][i]) + num;
            }
        }
    }
    ret = *max_element(&dp[n][1], &dp[n][n] + 1);
    cout << ret;
}