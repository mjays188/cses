#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1643
	// https://cses.fi/problemset/result/11391397/
	// https://cses.fi/problemset/result/11391505/
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	
	vector<ll> mx(n, INT_MIN);
	mx[0] = v[0];
	for(ll i=1;i<n;i++){
		if(mx[i-1] < 0)
			mx[i] = v[i];
		else
			mx[i] = v[i]+mx[i-1];
		//mx[i] = max(0ll, v[i]+mx[i-1]);
	}
	ll ans = *max_element(mx.begin(), mx.end());
	cout<<ans;
	return 0;
}
