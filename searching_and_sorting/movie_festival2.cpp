#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool myComparator(pair<ll, ll> a, pair<ll, ll> b){
	if(a.second < b.second)
		return true;
	else if(a.second == b.second && a.first < b.first)
		return true;
	return false;
}
int main(){
	// https://cses.fi/problemset/task/1632
	ll n, k;
	cin>>n>>k;
	vector<pair<ll, ll> > v;
	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), myComparator);
	for(int i=0;i<n;i++){
		cout<<v[i].first<<" "<<v[i].second<<",";
	}
	cout<<"\n";
	ll ans = k;
	multiset<ll> mst;
	set<ll> st;

	for(ll i=0;i<k;i++){
		mst.insert(v[i].second);
		if(st.find(v[i].second)==st.end())
			st.insert(v[i].second);
	}

	for(ll i=k;i<n;i++){
		// if ith movie can be watched, if there's an element smaller than v[i].first
		if(v[i].first >= *st.begin()){
			auto it = st.lower_bound(v[i].first);
			cout<<v[i].first<<" "<<v[i].second<<"-"<<*it<<"\n";
			if(it!=st.end()){
				cout<<"be "<<*it<<"\n";
				// try to find a movie ending time which <= starting time of ith movie
				if(v[i].first < *it)
					it--;
				auto mit = mst.find(*it);
				st.erase(it);
				mst.erase(mit);
			} else {
				cout<<"here - ";
				auto tbr = st.rbegin();
				auto mtbr = mst.find(*tbr);
				cout<<*tbr<<"-"<<*mtbr<<"\n";
				mst.erase(mtbr);
				if(mst.count(*tbr)==0)
					st.erase(*tbr);
			} 
			if(st.find(v[i].second)==st.end())
				st.insert(v[i].second);
			mst.insert(v[i].second);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
