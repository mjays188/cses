#include <bits/stdc++.h>
using namespace std;

int main(){
	// https://cses.fi/problemset/task/1069
	// https://cses.fi/problemset/result/11302798/
	string s;
	cin>>s;
	int ans = 1, c = 1;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1]){
			ans = max(ans, c);
			c = 1;
		} else {
			c++;
		}
	}
	ans = max(ans, c);
	cout<<ans;
}
