#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	//https://cses.fi/problemset/task/1084
	//https://cses.fi/problemset/result/11355763/
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> ds; // desired size of apartments
	vector<int> as; // available size of apartments
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ds.push_back(t);
	}
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		as.push_back(t);
	}
	// sort the desired and available sizes of houses
	sort(ds.begin(), ds.end());
	sort(as.begin(), as.end());

	int i=0, j=0, ans = 0;
	// start alloting houses those can be alloted(within +-k range of desired houses)
	while(i<n && j<m){
		// check if jth house can be alloted to ith applicant
		if(ds[i] >= as[j]-k && ds[i] <= as[j]+k){
			ans++;
			j++;
			i++;
		} else if(ds[i] < as[j]-k){
			// if desried size is not allocatable then we skip,
			// means available sizes are bigger, so we compare higher expectations now
			i++;
		} else if(ds[i] > as[j]+k){
			// means available sizes is smaller than expected, so we compare higher expectations now
			j++;
		}
	}
	cout<<ans;
	return 0;
}

