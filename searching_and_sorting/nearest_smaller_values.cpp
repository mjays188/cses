#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1645
	// https://cses.fi/problemset/result/11367054/
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}

	// find smaller to left
	stack<pair<ll, ll>> st;
	vector<ll> ans;
	st.push({v[0], 0});
	ans.push_back(0);
	for(ll i=1;i<n;i++){
		while(!st.empty() && v[i] <= st.top().first)
			st.pop();
		if(st.empty())
			ans.push_back(0);
		else
			ans.push_back(st.top().second + 1ll);
		st.push({v[i], i});
	}
	for(ll i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
