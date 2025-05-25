#include "bits/stdc++.h"
#define ll long long
#define MOD 1000000007
#define inf 1000000000000000000LL
 
using namespace std;

#define int long long


signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	vector<int> a(n), b(n);
	for(auto &x: a) cin>>x;
	for(auto &x: b) cin>>x;

	map<int,int> segX, segY;
	
	for(int i=0;i<n;i++) {
		if(a[i]<=b[i]) {
			if(!segX.count(a[i])) segX[a[i]] = b[i];
			else segX[a[i]] = max(segX[a[i]], b[i]);
		}
		else {
			if(!segY.count(b[i])) segY[b[i]] = a[i];
			else segY[b[i]] = max(segY[b[i]], a[i]);
		}
	}

	// Construct prefix maxima
	int mx = -inf;
	for(auto &x: segX) {
		mx = max(mx, x.second);
		x.second = mx;
	}

	mx = -inf;
	for(auto &x: segY) {
		mx = max(mx, x.second);
		x.second = mx;
	}


	// Find best swap
	int mxGain = 0;
	for(int i=0;i<n;i++) {
		if(a[i]<=b[i]) {
			auto it = segY.upper_bound(a[i]);
			if(it==segY.begin()) continue;

			it--;
			int overlap = min(it->second, b[i]) - a[i];
			mxGain = max(mxGain, 2*overlap);
		}
		else {
			auto it = segX.upper_bound(b[i]);
			if(it==segX.begin()) continue;

			it--;
			int overlap = min(it->second, a[i]) - b[i];
			mxGain = max(mxGain, 2*overlap);
		}
	}

	// Find ans = initial val — mxGain
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += abs(a[i]-b[i]);
	}

	ans -= mxGain;
	cout<<ans;
	
}