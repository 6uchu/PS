#include<bits/stdc++.h>
using namespace std;
int t, n, even, odd, num;
//amsminn 채환
//heeda0528 희원
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        even = 0;
        odd = 0;
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num & 1) odd++;
            else even++;
        }
        if(even == odd || (even > odd && even % 2 == 0) || (even < odd && odd  % 2 == 0)){
            cout << "heeda0528\n";
        }else{
            cout << "amsminn\n";
        }
    }
}