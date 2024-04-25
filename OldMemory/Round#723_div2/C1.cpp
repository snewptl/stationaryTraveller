#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,cnt;
ll a[maxn],b[maxn];
priority_queue<int,vector<int>,greater<int>>q;
int main(){
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		// if(a[i]<0)b[++cnt]=1;
	}
	ll sum=0,ans=0;
	
	for(int i=n;i>=1;i--){
		if(a[i]>=0){
			ans++,sum+=a[i];
			while(!q.empty()&&sum>=q.top()){
				sum-=q.top();q.pop();ans++;
			}
		}
		else {
			if(q.empty())sum=0;
			else {
				int p=q.top();p-=sum;
				sum=0;
				q.pop();q.push(p);
			}
			q.push(-a[i]);
		}
	}
	printf("%d\n",ans);

    return 0;
}