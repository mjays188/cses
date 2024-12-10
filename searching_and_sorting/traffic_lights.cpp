#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1163
	// https://cses.fi/problemset/result/11382493/
	ll x, n;
	cin>>x>>n;
	map<ll, ll> mp;

	set<ll> st;
	st.insert(0);
	st.insert(x);
	mp[x] = 1;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		// now for every insertion of light we find the position bulbs before and after that position,
		// and split the gap as per incoming bulb position

		auto lb = st.lower_bound(t), ub = st.upper_bound(t);
		lb--;
		ll d = *ub - *lb;
		ll dlb = t-*lb, dub = *ub-t;
		mp[d]--;
		mp[dlb]++;
		mp[dub]++;
		if(mp[d] == 0)
			mp.erase(d);
		// cout<<*lb<<" "<<*ub<<"\n";
		st.insert(t);
		cout<<(--mp.end())->first<<" ";
	}

	return 0;
}
