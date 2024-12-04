#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void h(vector<ll> v, ll size, ll s1, ll s2, ll *d){
	if(size==0)
		return;
	// iterate through all the items and include and exclude every item to check the minimum difference
	*d = min(*d, abs(s1-s2));
	// consider size-1(th) element in second group
	h(v, size-1, s1-v[size-1], s2+v[size-1], d);
	// now consider last element in first group
	h(v, size-1, s1, s2, d);
}
int main(){
	// https://cses.fi/problemset/task/1623
	// https://cses.fi/problemset/result/11327932/
	ll n, sum = 0;
	vector<ll> v;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
		sum += t;
	}
	ll d = INT_MAX * 1ll;
	h(v, n, sum, 0, &d);
	cout<<d;
	return 0;
}
