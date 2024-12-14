#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1644
	ll n, a, b;
	cin>>n>>a>>b;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	// declaring array mx: which stores the maximumSubarraySum till ith index from beginning
	vector<pair<ll, ll>> mx(n, {INT_MIN, 0});
	// if there's only 1 element in incoming array, then maximumSubarraySum as the on & only element
	mx[0] = {v[0], 1};
	for(ll i=1;i<n;i++){
		// if maximumSubarraySum till now is negative, then start considering array starting from ith idx for maximumSubarraySum  
		if(mx[i-1].first < 0 || mx[i-1].second==b){
			mx[i].first = v[i];
			mx[i].second = 1;
		}
		// add ith element to max sum subarray ending at (i-1)th idx
		else{
			mx[i].first = v[i]+mx[i-1].first;
			mx[i].second = mx[i-1].second + 1ll;
		}
	}
	// to get  maximumSubarraySum fetch the maximum Sum from mx array
	ll ans = INT_MIN;
	for(ll i=0;i<n;i++){
		// cout<<mx[i].first<<" "<<mx[i].second<<"\n";
		if(mx[i].second >=a && mx[i].second <=b)
			ans = max(ans, mx[i].first);
	}
	cout<<ans;
	return 0;
}
