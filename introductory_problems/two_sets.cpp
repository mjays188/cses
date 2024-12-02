#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1092
	// https://cses.fi/problemset/result/11307075/ 
	// this solution isn't accepted, it is logically correct, it partitions n numbers into two sets with equal sum
	ll n;
	cin>>n;

	// check if n(n+1)/2 is even or not
	ll k = (n*(n+1ll))/2ll;
	if(k&1){
		cout<<"NO";
	} else {
		k = k/2ll;
		// to get the group size
		ll c = 0, t = k, p = n;
		while(t>p){
			// keep subtracting largest element until it can be
			t-=p;
			p--;
			c++;
		}
		cout<<c+1<<"\n";
		cout<<t<<" ";
		for(int i=p+1;i<=n;i++)
			cout<<i<<" ";
		cout<<"\n";
		cout<<n-(c+1)<<"\n";
		for(int i=1;i<=p;i++){
			if(i!=t)
				cout<<i<<" ";
		}
	}
	return 0;
}
