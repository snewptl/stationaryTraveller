#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int a[maxn];
set<int>vis[maxn*30];
int flag=0;
int b[10],tot;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(flag)break;
		for(int j=i+1;j<=n;j++){
			if(flag)break;
			int temp=a[i]+a[j];
			vis[temp].insert(i);vis[temp].insert(j);
			if(vis[temp].size()>=4){
				tot=0;
				vis[temp].erase(i),vis[temp].erase(j);
				for(auto x:vis[temp])
					b[++tot]=x;
				if(tot>=2&&a[b[1]]+a[b[2]]==temp){
					printf("YES\n");
					printf("%d %d %d %d\n",b[1],b[2],i,j);
					flag=1;break;
				}
				if(tot>=3){
					if(a[b[1]]+a[b[3]]==temp){
						printf("YES\n");
						printf("%d %d %d %d\n",b[1],b[3],i,j);
						flag=1;break;
					}
					if(a[b[3]]==a[i]){
						printf("YES\n");
						printf("%d %d %d %d\n",b[1],b[2],b[3],i);
						flag=1;break;
					}
					else if(a[b[3]]==a[j]){
						printf("YES\n");
						printf("%d %d %d %d\n",b[1],b[2],b[3],j);
						flag=1;break;						
					}
					else {
						for(int k=2;k<=tot;k++){
							if(a[b[k]]+a[b[1]]!=temp)continue;
							printf("YES\n");
							printf("%d %d %d %d\n",b[k],b[1],i,j);
							flag=1;break;						
						}
					}
				}
				vis[temp].insert(i);vis[temp].insert(j);
			}
		}
	}
	if(!flag)printf("NO\n");

    return 0;
}