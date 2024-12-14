#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1661
	// the difference between this task and subArraySum1 is range of numbers
	ll n,x;
	cin>>n>>x;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	// variable sized window 
	// task : count all subarrays with sum x
	ll l=0, r=1, s=v[0], ans=0;
	while(l<=r && r<n){
		cout<<ans<<" "<<s<<",";
		// if window [l,r] sum is equal to x, record it & then remove the front element from window
		if(s==x){
			ans+=1ll;
			s-=v[l];
			l++;
		} else if(s<x){
			// if window sum is less than x, then keep appending elements to the window
			s += v[r];
			r++;
		} else {
			// if window sum is greater than desired than trim the first element
			s-=v[l];
			l++;
		} 
		// this way we would be able to gather all the subarrays that end at r=n-1, with sum x
	}
	// now to assess all subarrays which might start after l and end at r(for sure)
	while(l<n){
		ans+=(s==x ? 1 : 0);
		s-=v[l];
		l++;
	}
	cout<<ans;
	return 0;
}
