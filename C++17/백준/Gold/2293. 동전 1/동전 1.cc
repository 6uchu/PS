#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[100004];
vector<int> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        vec.push_back(a);
    }

    dp[0] = 1;

    for(int coin : vec){
        for(int i = coin; i <= k; i++){
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[k];
}