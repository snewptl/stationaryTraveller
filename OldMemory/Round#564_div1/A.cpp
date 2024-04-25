#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int a[maxn],b[maxn];
set<int>s;
int dis[maxn];
int t,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i])s.insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i])dis[b[i]]=i;
	}
	int flag=1,bk=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			bk=1;
			t=i;
			for(int j=2;j<=n;j++){
				int temp=i+j-1;
				if(temp>n)break;
				if(b[temp]!=j)flag=0;
			}
			for(int j=1;j<i;j++){
				if(s.empty())flag=0;
				if(!flag)break;
				int k=*s.begin();
				if(k!=n-i+j+1)flag=0;
				s.erase(k);
				if(b[j])s.insert(b[j]);
			}
			break;
		}
	}
	if(flag&&bk){
		printf("%d\n",t-1);return 0;
	}
	for(int i=1;i<=n;i++){
		if(i+ans<=dis[i])ans=dis[i]-i+1;
	}
	printf("%d\n",ans+n);

    return 0;
}