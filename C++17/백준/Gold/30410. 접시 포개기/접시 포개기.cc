#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int n, prevv, streak, cnt, max_, p;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    cin >> prevv;

    n--;
    if(prevv == 2) vec.push_back(2);
    else streak++;
    
    //get input k
    //if k = 2: push(k)
    //if k = 1: 
    //count number of 1s in a row and push(count)
    while(n--){
        int k;
        cin >> k;

        if(k == 2 && prevv == 1){
            vec.push_back(streak);
            vec.push_back(2);
            streak = 0;
        } 
        else if(k == 1){
            streak++;
        }else{
            vec.push_back(2);
        }
        prevv = k;
    }
    if(streak) vec.push_back(streak);

    //최대 연속되는 2의 개수를 셈
    for(int i = 0; i < size(vec); i++){
        if(!(vec[i] & 1)){
            cnt += vec[i] / 2;
        }else{
            //홀수면 홀수 - 1 / 2 더하고 비교 후 max_ 갱신
            //다시 세기 시작 
            cnt += (vec[i] - 1) / 2;
            if(max_ < cnt) max_ = cnt;
            cnt = (vec[i] - 1) / 2;
        }
    }
    if(max_ < cnt) max_ = cnt;

    /*
    0 1 2-3 4-7 8-15 <- max_
    1 2 4   8   16   <- ret
    */
   
    if(max_ == 0) cout << 1;
    else{
        int ret = 1;
        while(max_ >= ret){
            ret *= 2;
        }

        cout << ret;
    }
}