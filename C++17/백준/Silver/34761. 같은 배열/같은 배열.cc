#include<bits/stdc++.h>
using namespace std;
vector<int> a, b;
map<int, int> mp;
int n, flag = 1;
int num;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){  
        cin >> num;
        a.push_back(num);
        mp[num] = 1;
    }

    for(int i = 0; i < 2 * n; i++){
        cin >> num;
        if(i < n){
            if(a[i] == num) continue;
            else{
                flag = 0;
                break;
            }
        }else{
            if(mp[num] == 1) continue;
            else{
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
        cout << "YES";
    else
        cout << "NO";
}