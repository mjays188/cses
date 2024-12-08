#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool myComparator(pair<ll, ll> a, pair<ll, ll> b){
	if(a.second < b.second)
		return true;
	else if(a.second == b.second && a.first < b.first)
		return true;
	return false;
}
int main(){
	// https://cses.fi/problemset/task/1629
	// https://cses.fi/problemset/result/11362858/
	ll n;
	cin>>n;
	vector<pair<ll, ll> > v;
	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), myComparator);
	/*
	for(int i=0;i<n;i++){
		cout<<v[i].first<<" "<<v[i].second<<",";
	}
	*/
	// now count all the movies that can be watched
	ll ans = 1;
	ll k = v[0].second;
	for(ll i=1;i<n;i++){
		if(v[i].first >= k){
			ans++;
			k = v[i].second;
		}
	}
	cout<<ans;
	return 0;
}
