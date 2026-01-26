#include <bits/stdc++.h>
using namespace std;
string a, b;
int ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    for(int j = 0; j < a.length(); j++){
        if(a[j] != b[j]) ret++;
    }

    for(int i = 0; i <= b.length() - a.length(); i++){
        int cnt = 0;
        for(int j = 0; j < a.length(); j++){
            if(a[j] != b[j + i]) cnt++;
        }
        ret = min(cnt, ret);
    }

    cout << ret;

    return 0;
}