#include<bits/stdc++.h>
using namespace std;
map<long long, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a] = 1;
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        long long a; cin >> a;
        if(mp[a]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}