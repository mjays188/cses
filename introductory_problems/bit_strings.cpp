#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1617
	// bit strings
	// https://cses.fi/problemset/result/11307701/
	ll n;
	cin>>n;
	ll MOD = (pow(10,9) + 7)*1ll;
	ll ans = 1ll;
	ll base = 2ll;
	ll t = n;
	while(t){
		if(t&1){
			ans *= base;
			ans = ans % MOD;
		}
		base *= base;
		t/=2;
		base = base % MOD;
	}
	cout<<ans;
	return 0;
}
