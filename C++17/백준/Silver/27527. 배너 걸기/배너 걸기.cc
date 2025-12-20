#include<bits/stdc++.h>
using namespace std;
int n, m, num, k;
vector<int> a;
int l2st[1000004];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    k = ceil((double)(9 * m) / 10);
    //k = (9 * m + 9) / 10; //(a + b - 1) / b
    for(int i = 0; i < n; i++){
        cin >> num;
        a.push_back(num);
    }

    for(int i = 0; i < n; i++){
        if(i >= m) l2st[a[i - m]]--;
        if(++l2st[a[i]] >= k){
            cout << "YES";
        return 0;
        }
    }

    cout << "NO";
}