#include <bits/stdc++.h>
using namespace std;
int cnt, pos;
string st, ret;
int alp[130];
stack<char> stk;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> st;
	
	for(char c : st){
		alp[c]++;
	}
	
	for(int i = 'A'; i <= 'Z'; i++){
		if(alp[i]&1) {
			pos = i;
			cnt++;
		}
	}
	
	if(cnt > 1){
		cout << "I'm Sorry Hansoo\n";
	}else{
		for(int i = 'A'; i <= 'Z'; i++){
			for(int j = 0; j < alp[i]/2; j++){
				ret += (char)i;
				stk.push(i);
			}
		}
		if(cnt)	ret += (char)pos;
		while(!stk.empty()){
			ret += stk.top();
			stk.pop();
		}
		cout << ret;
	}
}