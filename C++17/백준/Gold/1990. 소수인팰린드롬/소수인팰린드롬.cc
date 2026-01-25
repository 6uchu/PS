#include <bits/stdc++.h>
using namespace std;
int a, z;

vector<bool> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> z;

    v.resize(z + 1);

    fill(v.begin(), v.end(), 0);
    
    for (int i = 2; i * i <= z; i++) {
        if (v[i]) continue;
        for (int j = i * i; j <= z; j += i){
            v[j] = 1;
        }
    }

    for(int i = a; i <= z; i++){
        if(v[i] != 1){
            int flag = 1;
            if(i >= a && i <= z){
                string str = to_string(i);
                for(int j = 0; j < str.length() / 2; j++){
                    if(str[j] != str[str.length() - 1 - j]) {flag = 0; break;}
                }
                if(flag)
                    cout << i << '\n';
            }
        }
    }
    
    cout << -1;

    return 0;
}