#include <bits/stdc++.h>
using namespace std;
string str, fr, nd, tstr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int ind = 0, n; cin >> n;
	cin >> str;
	while(str[ind] != '*')
		ind++;
	
	fr = str.substr(0, ind);
	nd = str.substr(ind + 1);
	while(n-- != 0){
		cin >> tstr;
		if(fr.length() + nd.length() <= tstr.length() && 
		nd == tstr.substr(tstr.length() - nd.length()) &&
		fr == tstr.substr(0, fr.length())){
			cout << "DA\n"; 
		}else{
			cout << "NE\n";
		}
	}
}