#include <bits/stdc++.h>
using namespace std;
//내 회사에 1.05 초과로 구매
int n, m, ret;
double a;
string str;
map<string, double> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> str;
        cin >> mp[str];
    }
    for(int i = 0; i < m; i++){
        cin >> str; cin >> a;
        if(a > 1.05 * mp[str]){
            ret++;
        }
    }
    cout << ret;
    return 0;
}