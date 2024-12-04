#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int main(){
	// cout<<"\nHello world";
	// https://cses.fi/problemset/task/2431
	/* the digits in the infinite can be seen as consecutive sequence of groups
	 * each group has 9*pow(10, (i-1)) numbers, totalling to 9*pow(10, (i-1))*i digits
	 * so if i=2 means, group of all 2 digit numbers, totalling to 9*10*2(180) digits 
	 *
	 * So asked the digit at the kth position, we first find it belongs to group of which digit numbers
	 * then subtract the cumulative sum of previous groups digits, 
	 * now we find the number by dividing the differnece by i
	 * the we find digit by finding mod i
	 */
	int q;
	cin>>q;
	for(int i=1; i<=q; i++){
		ll k;
		cin>>k;
		ll p = 0;
		ll sum = 0;
		ll nos = 0;
		while(true){
			p+=1ll;
			sum += 9ll * pow(10ll, p-1ll) * p;
			nos += 9ll * pow(10ll, p-1ll);
			cout<<sum<<","<<nos<<"\n";
			if(sum>=k)
				break;
		} 
		cout<<p<<endl;
		// now we know sum == k or sum > k
		if(sum==k)
			cout<<9;
		else {
			cout<<sum<<" "<<nos<<"\n";
			sum -= 9ll * pow(10ll, p-1ll) * p;
			nos -= 9ll * pow(10ll, p-1ll);
			cout<<sum<<" "<<nos<<"\n";
			// difference would be k - sum
			ll d = k - sum;
			// getting the number
			ll no_diff = d/p;
			cout<<d<<" "<<no_diff<<" ";
			ll mod = d%p;
			ll the_num = nos + no_diff;
			cout<<mod<<" "<<the_num<<" ";
			// get the mod(th) digit from the_num
			if(mod){
				the_num+=1ll;
				ll k = p - mod;
				//cout<<the_num<<" ";
				while(k){
					the_num /= 10ll;
					k-=1ll;
				}
			}
			cout<<the_num % 10ll;
		}
			cout<<"\n";
	}
	return 0;
}
