#include <bits/stdc++.h>
using namespace std;

int main(){
	// https://cses.fi/problemset/task/1070
	// https://cses.fi/problemset/result/11302886/
	int n;
	cin>>n;
	if(n==1 || n>3){
		for(int i=2;i<=n;i+=2){
			cout<<i<<" ";
		}
		for(int i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
	} else 
		cout<<"NO SOLUTION";
	return 0;
}
