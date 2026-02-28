#include <bits/stdc++.h>
using namespace std;
int n, k, t, prew;
long long ret;
vector<int> v, w;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> t;
    ret = t;


    while(n--){
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    while(k){
        for(int i = v.size() - 1; i >= 0; i--){
            if(v[i] < ret){
                ret += v[i];
                v.erase(v.begin() + i);
                k--;
                break;
            }
            if(i == 0){
                cout << ret;
                return 0;
            }
        }
    }

    cout << ret;
    return 0;
}