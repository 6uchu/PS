#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, ret = 1; 
//a^b -> a^b/2 과정 반복 
ll findret(ll ret, ll b){
	if(b == 1){
		return ret * a % c;
	}
	ret = findret(ret, b/2);
	ret = (ret % c) * (ret % c) % c;
	if(b & 1){
		ret = ret * a % c;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	
	ret = findret(ret, b);
	
	cout << ret;
}