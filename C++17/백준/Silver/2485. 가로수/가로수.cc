#include<bits/stdc++.h>
using namespace std;
int n, num, GCD, first, last;
set<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> first;
    cin >> num;
    GCD = num - first;

    for(int i = 2; i < n - 1; i++){
        cin >> num;
        st.insert(num - first);
    }
    cin >> last;
    st.insert(last - first);

    for(int a : st){
        GCD = gcd(GCD, a);
    }

    cout << (last - first)/GCD - st.size() - 1;
}