#include <bits/stdc++.h>
using namespace std;
int arr[2][10], info[9];

int solve(){
    int cnt = 0, cntt = 0, isret = -1, ii, iii, sum = 0;
    
    for(int i = 1; i <= 9; i++){
        if(arr[1][i] == 1){
            ii = i;
            cnt++;
        }
        //확정 정답
        if(arr[1][i] >= 2){
            if(isret != -1) return -1;
            isret = i;
        }
    }
    //확정 정답이 없는 경우 && T가 하나인 경우
    if(isret == -1 && cnt == 1){
        //한 수에 T F 하나씩 있는 경우
        
        for(int i = 1; i <= 9; i++){
            if(arr[0][i] >= 1){
                sum += i;
                cntt++;
            }
        }
        if(cntt == 7) {
            if(45 - sum - ii <= 9)
                return 45 - sum - ii;
        }
        else if(arr[0][ii] == arr[1][ii]) return ii;
        else return -1;
    }else{
        if(arr[0][isret] == 1 && cnt == 0) return isret;
        if(arr[0][isret] == 0 && cnt == 1) return isret;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 9;
    while(n--){
        int a, b;
        cin >> a >> b;

        ++arr[a][b];
    }

    cout << solve();
    return 0;
}