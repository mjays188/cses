#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1094
	// https://cses.fi/problemset/result/11302851/
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	ll ans = 0;
	for(int i=1;i<n;i++){
		if(v[i] < v[i-1]){
			ans += (v[i-1]-v[i])*1ll ;
			v[i] = v[i-1];
		}
	}
	cout<<ans;
	return 0;
}
