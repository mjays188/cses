#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	// https://cses.fi/problemset/task/1077
	ll n, k;
	cin>>n>>k;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	ll j = 0, md = 0, mdc = 0;
	multiset<ll> st;
	auto mdi = st.begin();
	while(j<n){
		st.insert(v[j]);
		if(j>=k) {
			// remove (k-j)th element from multiset 
			auto it = st.find(v[j-k]);
			// when recalculating the median in o(1)
			// if incoming value and outgoing values both are less than or greater than existing median
			if((md > v[j-k] && md > v[j])){
				mdc += (v[j-k]-v[j]);
			}
			else if (v[j-k] > md && v[j] > md)){
				mdc += (v[j]-v[j-k]);
			}
			// if incoming value and outgoing value are other opposite side(1 is lesser and another is greater
			else if(md > v[j-k] && md < v[j]) {
				advance(mdi, 1);

			} 
			// incoming < md and outgoing > md
			else if(md < v[j-k] && md > v[j]) {
				mdi--;
			} 
			else if(v[j-k]==md){
				// median itself is outgoing
				if(v[j] >= md){
					advance(mdi, 1);
				} else {
					mdi--;
				} 
				// 7 3
				// 6 6 6 5 6 6 6
				// for case when there are multiple values equal to median,
				// the find function at line 25 can return pointer to any matching value, and 
				// due to this randomness, if the iterator being erased(it) points to same iterator - pointing to new median, then segmentation fault will occur
				// to avoid these scene we advance the mdi iterator by 1(it works because multiple values are definitely present)
				if(mdi==it){
					mdi++;
				}
			}
			else if(v[j]==md){
				if(v[j-k] <= md){
					advance(mdi, 1);
				}
			}
			st.erase(it);
			/*
			for(auto p:st)
				cout<<p<<",";
			cout<<endl;
			*/
			md = *mdi;
			cout<<md<<" ";
		}
		// aim is to find next median in constant time
		if(j==k-1){
			// calculating median for the first time takes linear time
			mdi = next(st.begin(), (k-1)/2); // https://en.cppreference.com/w/cpp/iterator/next
			md = *mdi;
			// calculate the diff between all elements of set and the median: gives us the cost to make all elements equal
			for(auto it = st.begin();it!=st.end();it++){
				mdc += abs(md - *it);
			}
			cout<<mdc<<" ";
		} 
		j++;
	}
	return 0;
}
