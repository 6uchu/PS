#include<bits/stdc++.h>
using namespace std;
char c[10];
int used[10], k, done;
string max_, min_;

void findMax(int prev, int dep){
    if(dep == k + 1) {done = 1; return;}
    for(int i = 9; i >= 0; i--){
        if(used[i]) continue;

        if(dep > 0){
            if(c[dep - 1] == '>' && !(prev > i)) continue;
            else if(c[dep - 1] == '<' && !(prev < i)) continue;
        }
        
        used[i] = 1;
        max_.push_back(char('0' + i));
        findMax(i, dep + 1);
        if(done) return;
        used[i] = 0;
        max_.pop_back();
    }
}

void findMin(int prev, int dep){
    if(dep == k + 1) {done = 1; return;}

    for(int i = 0; i <= 9; i++){
        if(used[i]) continue;
        
        if(dep > 0){
            if(c[dep - 1] == '>' && !(prev > i)) continue;
            else if(c[dep - 1] == '<' && !(prev < i)) continue;
        }
        
        used[i] = 1;
        min_.push_back(char('0' + i));
        findMin(i, dep + 1);
        if(done) return;
        used[i] = 0;
        min_.pop_back();
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> c[i];
    //최대값 구하기
    memset(used, 0, sizeof(used));
    done = 0;
    findMax(-1, 0);
    cout << max_ << '\n';

    //최소값 구하기
    memset(used, 0, sizeof(used));
    done = 0;
    findMin(-1, 0);
    cout << min_ << '\n';
}