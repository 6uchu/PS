#include<bits/stdc++.h>
using namespace std;
int my, mx, n, ret;
char k;

int main(){
    cin >> my >> mx >> n;
    
    int line;
    for(int i = 0; i < my; i++){
        line = 0;
        for(int j = 0; j < mx; j++){
            cin >> k;
            if(k == '1'){
                ret += max(0, line - n + 1);
                line = 0;
                continue;
            }
            line++;
        }
        ret += max(0, line - n + 1);
    }

    cout << ret;
}