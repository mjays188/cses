#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1618/
	// https://cses.fi/problemset/result/11308041/
	ll n;
	cin>>n;
	ll k = 5ll;
	ll ans = 0;
	while(n >= k){
		ans += (n/k);
		k*=5ll;
	}
	cout<<ans;
	return 0;
}
