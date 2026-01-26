#include <bits/stdc++.h>
using namespace std;
int t, ret;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    regex r("(100+1+|01)+");

    while(t--){
        cin >> str;
        if(regex_match(str, r)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}