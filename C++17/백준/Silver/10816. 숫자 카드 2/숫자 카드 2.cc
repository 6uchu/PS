#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int N, M, num;
//1 ≤ N, M ≤ 500,000
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        mp[num]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        cout << mp[num] << ' ';
    }
}