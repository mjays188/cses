#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void toh(int n, int source, int dest, int help, vector<pair<int, int>> *v){
	if(n==1){
		//cout<<source<<" "<<dest<<" "<<help<<"\n";
		v->push_back({source, dest});
		return;
	}
	toh(n-1, source, help, dest, v);
	toh(1, source, dest, help, v);
	toh(n-1, help, dest, source, v);
}
/*
 * 1 -> 1 3
 * 2 -> 1 2, 1 3, 2 3
 * */

int main(){
	// https://cses.fi/problemset/task/2165
	// https://cses.fi/problemset/result/11637940/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  	cout.tie(nullptr);
	ll n;
	cin>>n;
	vector<pair<int, int>> v;
	toh(n, 1, 3, 2, &v);
	cout<<v.size()<<"\n";
	for(auto i:v)
		cout<<i.first<<" "<<i.second<<"\n";
	return 0;
}
