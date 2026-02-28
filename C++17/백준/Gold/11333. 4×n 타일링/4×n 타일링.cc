#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int t, n;
long long dp[10004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 13;

    for(int i = 3; i <= 10000; i++) {
		dp[i] = ((5 * dp[i - 1]) % MOD - (3 * dp[i - 2] % MOD) + MOD + dp[i - 3]) % MOD;
	}

    while(t--){
        cin >> n;
        if(n % 3) { cout << 0 << '\n'; }
        else { cout << dp[n / 3] << '\n'; }
    }
    

    return 0;
}