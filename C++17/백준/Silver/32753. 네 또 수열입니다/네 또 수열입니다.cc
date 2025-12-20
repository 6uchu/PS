#include<bits/stdc++.h>
using namespace std;
int n, k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    //1..n * k
    
    if(n == 2 && k == 1)
        cout << "1 2";
    else if(n == 1)
        for(int i = 0; i < k; i++) cout << "1 ";
    else
        cout << "-1";
}