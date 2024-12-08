#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1074/
	// https://cses.fi/problemset/result/11364086/
	ll n;
	cin>>n;
	vector<ll> v;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	ll d = 0;
	for(ll i=1;i<n;i++)
		d+=v[i]-v[0];
	
	ll mn = d;
	/*
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl<<d;
	*/
	// now keep updating the d, basically calculate the difference of ith element with remaining elements and find the minimum
	for(ll i=1;i<n;i++){
		d-=(n-i)*(v[i]-v[i-1]);
		d+=(i)*(v[i]-v[i-1]);
		//cout<<d<<"\n";
		mn = min(d, mn);
	}
	cout<<mn;
	return 0;
}
