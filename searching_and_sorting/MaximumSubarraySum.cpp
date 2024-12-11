#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1643
	// https://cses.fi/problemset/result/11391397/
	// https://cses.fi/problemset/result/11391505/
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	// declaring array mx: which stores the maximumSubarraySum till ith index from beginning
	vector<ll> mx(n, INT_MIN);
	// if there's only 1 element in incoming array, then maximumSubarraySum as the on & only element
	mx[0] = v[0];
	for(ll i=1;i<n;i++){
		// if maximumSubarraySum till now is negative, then start considering array starting from ith idx for maximumSubarraySum  
		if(mx[i-1] < 0)
			mx[i] = v[i];
		// add ith element to max sum subarray ending at (i-1)th idx
		else
			mx[i] = v[i]+mx[i-1];
	}
	// to get  maximumSubarraySum fetch the maximum Sum from mx array
	ll ans = *max_element(mx.begin(), mx.end());
	cout<<ans;
	return 0;
}
