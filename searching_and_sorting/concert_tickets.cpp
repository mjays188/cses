#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1091/
	// https://cses.fi/problemset/result/12369578/
	ll n, m;
	cin>>n>>m;
	vector<ll> tp, cb;
	map<ll, ll> mp;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		tp.push_back(t);
		mp[t]++;
	}
	// for every customer get the closest ticket available using lower bound
	for(ll i=0;i<m;i++){
		ll t;
		cin>>t;
		map<ll,ll>::iterator it = mp.lower_bound(t);
		// check if it->first == t, if yes then we got the nearest value
		if(it->first == t || it != mp.begin()){
			it = (it->first != t) ? --it : it;
			cout<<it->first<<" ";
			it->second--;
			if(it->second==0)
				mp.erase(it);
		}
		// else if there exist a smaller value than it, then return it, 
		else {
			cout<<-1<<" ";
		}
		/* else return -1
		else {
			it--;
			cout<<it->first<<" ";
			it->second--;
			if(it->second==0)
				mp.erase(it);
		}
		*/
	}
	return 0;
}
