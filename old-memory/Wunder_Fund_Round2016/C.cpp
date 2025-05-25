#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
pair<int,int>a[maxn];
map<pair<int,int>,int>mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=make_pair(x,y);
		mp[a[i]]=i;
	}
	sort(a+1,a+n+1);
	int x1=a[1].first,x2=a[2].first;
	int y1=a[1].second,y2=a[2].second;
	for(int i=3;i<=n;i++){
		if(1LL*(y1-a[i].second)*(x2-a[i].first)==1LL*(y2-a[i].second)*(x1-a[i].first))continue;
		printf("%d %d %d\n",mp[a[1]],mp[a[2]],mp[a[i]]);
		break;
	}
    return 0;
}