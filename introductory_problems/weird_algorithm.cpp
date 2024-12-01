#include <bits/stdc++.h>
using namespace std;

int main(){
	// https://cses.fi/problemset/task/1068
	// result: https://cses.fi/problemset/result/11298769/
	long long n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1) {
		n = (n&1) ? 3*n + 1 : n/2;
		cout<<n<<" ";
	}
	return 0;
}
