#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1643
	// https://cses.fi/problemset/result/11391397/
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	
	vector<ll> mx(n, INT_MIN);
	ll bmx = 0;
	for(ll i=0;i<n;i++){
		bmx+=v[i];
		mx[i] = max(bmx, mx[i]);
		if(bmx < 0)
			bmx = 0;
	}
	ll ans = *max_element(mx.begin(), mx.end());
	cout<<ans;
	return 0;
}
