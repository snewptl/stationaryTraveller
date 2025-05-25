#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int cnt;
int a[maxn];
int main(){
    int T,n;scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i])cnt++;
	}
    while(T--){
        int t,x;
		scanf("%d%d",&t,&x);
		if(t==1){
			if(a[x])cnt--;
			else cnt++;
			a[x]=1-a[x];
		}
		if(t==2){
			if(cnt>=x)printf("1\n");
			else printf("0\n");
		}
    }


    return 0;
}