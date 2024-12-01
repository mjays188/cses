#include <bits/stdc++.h>
using namespace std;

int main(){
	// https://cses.fi/problemset/task/1083
	// https://cses.fi/problemset/result/11298845/
	int n;
	cin >> n;
	int nxor = 0;
	for(int i=1;i<=n;i++) {
		nxor ^= i;
	}
	int xornm1 = 0;
	for(int i=1;i<n;i++){
		int t;
		cin >> t;
		xornm1 ^= t;	
	}
	cout<< (xornm1 ^ nxor);
	return 0;
}
