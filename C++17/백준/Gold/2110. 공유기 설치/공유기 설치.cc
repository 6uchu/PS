/*
입력된 숫자 최소값에서 최대까지의 거리를 a라고 할 때
1부터 a까지의 수 중 조건을 만족하는 가장 큰 수를 구해야 한다.

조건을 만족하는 수를 이분탐색
중앙값이 조건을 만족한다면 크기가 더 큰 스팩트럼 탐색(오른쪽)
                아니라면 크기가 더 작은 스팩트럼 탐색(왼쪽)
*/
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> v;

bool can(int dist){
    int cnt = 1;
    int last = v[0];

    for(int i = 1; i < n; i++){
        if(v[i] - last >= dist){
            cnt++;
            last = v[i];
        }
    }
    return cnt >= c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int l = 1;
    int r = v[n - 1] - v[0];
    int ret = 0;

    while(l <= r){
        int mid = (l + r) / 2;
        if(can(mid)){
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ret;
}