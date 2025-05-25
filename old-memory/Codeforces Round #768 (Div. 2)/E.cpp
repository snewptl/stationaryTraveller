#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int lst[maxn];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			lst[a[i]]=i;
		}
		int ed=0,pre=0,cnt=0,ans=0,temp=0;
		int i=1;
		while(i<=n){
			if(ed<lst[a[i]]){
				ed=lst[a[i]];
				cnt++;
				while(ed!=i){
					int flag=0,temp=ed;
					for(;i<temp;i++){
						if(lst[a[i]]>ed)ed=lst[a[i]],flag=1;	
					}
					if(flag)cnt++;
					
				}
			
			}
			ans+=max(ed-pre-(cnt+1),0);
			// printf("%d %d %d\n",pre,ed,cnt);
			pre=ed;
			cnt=0;
			i=ed+1;
		}
		printf("%d\n",ans);
		
	}


	return 0;
}