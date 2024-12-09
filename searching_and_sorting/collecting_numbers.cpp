#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool myComp(pair<ll, ll> a, pair<ll, ll> b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first && a.second < b.second)
		return true;
	return false;
}
int main(){
	// https://cses.fi/problemset/task/2216
	// https://cses.fi/problemset/result/11376200/
	ll n;
	cin>>n;
	vector<pair<ll, ll>> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back({t, i});
	}
	sort(v.begin(), v.end(), myComp);
	ll ans = 1;
	for(ll i=1;i<n;i++){
		if(v[i].second < v[i-1].second)
			ans+=1ll;
	}
	cout<<ans;
	return 0;
}
