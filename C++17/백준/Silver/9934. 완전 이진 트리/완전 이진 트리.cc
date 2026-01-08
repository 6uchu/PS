//preorder 입력을 트리 구조로 출력
#include<bits/stdc++.h>
using namespace std;
int k, arr[1030], end_;
queue<pair<int, int>> q;

int main(){
    cin >> k;
    end_ = pow(2, k) - 1;
    for(int i = 0; i < end_; i++)
        cin >> arr[i];
    
    q.push({0, end_ - 1});
    while(q.size()){
        int l, r;
        tie(l, r) = q.front(); q.pop();
        int m = (l + r) / 2;
        
        cout << arr[m] << ' ';
        if(l < r){
            q.push({l, m - 1});
            q.push({m + 1, r});
        }
        if(r == end_ - 1) cout << '\n';
    }
}