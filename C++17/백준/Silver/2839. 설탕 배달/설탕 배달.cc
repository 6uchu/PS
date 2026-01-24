#include <bits/stdc++.h>
using namespace std;
int n, tn, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    f = n / 5;
    tn = n - 5 * f;
    while(tn % 3){
        if(f <= 0 && tn % 3){
            cout << -1;
            return 0;
        }
        f--;
        tn += 5;
    }
    cout << f + tn / 3;
    return 0;
}