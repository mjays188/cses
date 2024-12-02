#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	// https://cses.fi/problemset/task/1754/
	// https://cses.fi/problemset/result/11308935/
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a, b;
		cin>>a>>b;
		if(a>b){
			if(a > 2*b)
				cout<<"NO";
			else if((a+b)%3==0 || a==2*b)
				cout<<"YES";
			else 
				cout<<"NO";
		} else if(a<b){
			if(b > 2*a)
				cout<<"NO";
			else if((a+b)%3==0 || 2*a==b)
				cout<<"YES";
			else 
				cout<<"NO";
		} else {
			if((a+b)%3==0)
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<"\n";
	}
	return 0;
}
