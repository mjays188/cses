#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1072
	// https://cses.fi/problemset/result/11306568/
	
	ll n;
	cin>>n;
	if(n==1)
		cout<<0;
	else {
		cout<<"0\n6\n";
		for(ll i=3;i<=n;i+=1ll){
			ll k = pow(i, 2ll);
			ll t = (k*(k-1))/2ll;
			ll m = ((i-2ll)*(i-1ll)/2) * 8ll;
			cout<<(t-m)<<"\n";
		}
	}
	return 0;
}
