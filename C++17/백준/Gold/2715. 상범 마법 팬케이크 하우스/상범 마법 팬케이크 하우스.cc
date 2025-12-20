#include<bits/stdc++.h>
using namespace std;
int t, n, flipcnt;
vector<int> vec;

void swap(int a, int b){
    int tmp = vec[a];

    vec[a] = vec[b];
    vec[b] = tmp;
}

void flip(int a){
    stack<int> stk;
    for(int i = 0; i < a; i++)
        stk.push(vec[i]);
    for(int i = 0; i < a; i++){
        int b;
        if(!stk.empty())
            b = stk.top();            
        vec[i] = -b;
        stk.pop();
    }
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--){
        vec.clear();
        int k = 0;
        int ind, max_ = -1;
        vector<int> ret;
        
        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            vec.push_back(a);
        }
        
        for(int j = n; j > 1; j--){
            if(vec[j - 1] == j) continue;
            for(int l = 0; l < j; l++){
                if(j == abs(vec[l])){
                    ind = l;
                    break;
                }
            }
            if(ind == 0){
                if(vec[ind] > 0){
                    ret.push_back(1);
                    k += 1;
                }
                ret.push_back(j);
                k += 1;

                flip(j);
            }else{
                flip(ind + 1);
                ret.push_back(ind + 1);
                if(vec[0] > 0){
                    k++;
                    ret.push_back(1);
                }
                k += 2;
                flip(j);
                ret.push_back(j);
            }
        }
        if(vec[0] < 0){
            ret.push_back(1);
            k++;
        }

        cout << k << ' ';
        for(int a : ret)
            cout << a << ' ';
        cout << '\n';
    }
}