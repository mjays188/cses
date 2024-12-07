#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1621
	// https://cses.fi/problemset/result/11355353/
	int n, ans = 0;
	set<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(s.find(t)==s.end()){
			ans++;
			s.insert(t);
		}
	}
	cout<<ans;
	return 0;
}
