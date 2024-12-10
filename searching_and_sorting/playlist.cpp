#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1141
	// https://cses.fi/problemset/result/11379846/
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	ll prevIdx = 0, ans = 1ll;	//, c = 1ll;
	map<ll, ll> mp;
	mp[v[0]] = 0;
	for(ll i=1;i<n;i++){
		if(mp.find(v[i])!=mp.end()){
			ans = max(ans, i-prevIdx);
			// mp[v[i]] can be smaller than previous index, in that case we would want to skip updating prevIdx
			// means that after prevIdx, there is only 1 copy of v[i] present, which is what needs to be considered
			prevIdx = max(prevIdx, mp[v[i]] + 1);
		}
		mp[v[i]] = i;
	}
	// recalculate ans, incase there is are all unique elements towards end of iteration
	ans = max(ans, n-prevIdx);
	cout<<ans;
	return 0;
}
