#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
bool myComparator(pair<ll, ll> a, pair<ll, ll> b) {
	if(a.first < b.first)
		return true;
	else if(a.first == b.first && a.second < b.second)
		return true;
	return false;
}
int main(){
	// https://cses.fi/problemset/task/1630
	// https://cses.fi/problemset/result/11370348/
	ll n;
	cin>>n;
	vector<pair<ll, ll>> v;
	for(ll i=0;i<n;i++){
		ll t,s;
		cin>>t>>s;
		v.push_back({t,s});
	}
	// sort the tasks in increasing order of durations 
	sort(v.begin(), v.end(), myComparator);
	ll s = 0, t = 0;
	
	for(ll i=0;i<n;i++){
		t+=v[i].first;
		s += (v[i].second - t);
	}
	cout<<s;
	return 0;
}
