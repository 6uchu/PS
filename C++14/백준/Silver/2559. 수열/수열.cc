#include <bits/stdc++.h>
using namespace std;
int temp, n, k, psum[100004], cnt, maxi = INT_MIN;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	cnt = k;
	for(int i = 1; i <= n; i++){
		cin >> temp; psum[i] = psum[i-1] + temp;
	}	
	
	for(int i = k; i <= n; i++){
		int sum = psum[i] - psum[i - k];
		if(sum > maxi) maxi = sum;
	}
	cout << maxi << '\n';
}