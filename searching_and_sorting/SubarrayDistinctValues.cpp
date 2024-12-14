#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1660
	// https://cses.fi/problemset/result/11395207/
	ll n,x;
	cin>>n>>x;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	// variable sized window 
	// task : count all subarrays with atmost k distinct values
	ll l=0, r=1, s=v[0], ans=0;
	set<ll> st;
	if(x==1){
		cout<<n;
		return 0;
	}
	// x > 1
	ans += n;
	st.insert(v[l]);
	while(l<=r && r<n){
		//cout<<ans<<" "<<s<<",";
		// if window [l,r] sum is equal to x, record it & then remove the front element from window
		//cout<<st.size()<<" "<<ans<<" "<<l<<" "<<r<<",";
		if(st.size()<=x){
			// if window sum is less than x, then keep appending elements to the window
			if(st.size()>1)
				ans+=1ll;
			if(st.find(v[r])==st.end()){
				st.insert(v[r]);
			} else {
				// means the count distinct didn't increase, and we have a new subarray
				ans+=1ll;
			}
			r++;
		} else {
			// if window sum is greater than desired than trim the first element
			st.erase(v[l]);
			l++;
		} 
		//cout<<st.size()<<" "<<ans<<" "<<l<<" "<<r<<"\n";
		// this way we would be able to gather all the subarrays that end at r=n-1, with sum x
	}
	// now to assess all subarrays which might start after l and end at r(for sure)
	while(l<n-1){
		ans+=(st.size()<=x && st.size() > 1 ? 1 : 0);
		st.erase(v[l]);
		l++;
	}
	cout<<ans;
	return 0;
}
