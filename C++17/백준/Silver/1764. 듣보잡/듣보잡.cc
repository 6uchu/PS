#include<bits/stdc++.h>
using namespace std;
int N, M, cnt;
string str;
map<string, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        mp[str]++;
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        if(mp[str]){
            mp[str]++;
            cnt++;
        }
    }

    cout << cnt << '\n';
    for(auto a : mp){
        if(a.second == 2){
            cout << a.first << '\n';
        }
    }
}