#include <bits/stdc++.h>
using namespace std;
string str;
int cnt, n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	while(n--){
		stack<char> stk;
		cin >> str;
		for(char c: str){
			if(stk.size() && stk.top() == c){
				stk.pop();
			}else{
				stk.push(c);
			}
		}
		if(!stk.size()) cnt++;
	}
	cout << cnt << '\n';
}