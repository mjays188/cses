#include <bits/stdc++.h>
using namespace std;

int main(){
	// https://cses.fi/problemset/task/1640
	// https://cses.fi/problemset/result/11363596/
	int n, x;
	cin>>n>>x;
	vector<int> v;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	if(v.size() < 2){
		cout<<"IMPOSSIBLE";
		return 0;
	}

	map<int, int> s;
	s[v[0]] = 0;
	bool f = false;
	for(int i=1; i<n; i++){
		if(s.find(x-v[i])!=s.end()){
			cout<<i+1<<" "<<s[x-v[i]]+1;
			f = true;
			break;
		} else 
			s[v[i]] = i;
	}
	if(!f)
		cout<<"IMPOSSIBLE";
	return 0;
}
