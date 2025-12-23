#include <bits/stdc++.h>
using namespace std;

char c[14]; //max 9개
int n[14]; //max 10개
int a, num, ret = -987654321;
int cc, nn;

int cal(int k, int front, int rear){
    if(c[k] == '+') return front + rear;
    if(c[k] == '-') return front - rear;
    if(c[k] == '*') return front * rear;
}

void go(int i, int val){
    if(i == nn - 1){
        if(ret < val) ret = val;
        return;
    }

    go(i + 1, cal(i, val, n[i + 1]));
    if(i + 2 < nn)
        go(i + 2, cal(i, val, cal(i + 1, n[i + 1], n[i + 2])));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;
    string str; cin >> str;

    for(int i = 0; i < num; i++){
        if(i & 1) c[cc++] = str[i];
        else n[nn++] = str[i] - '0';
    }

    go(0, n[0]);

    cout << ret;
}