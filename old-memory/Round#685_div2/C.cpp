#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k;
char a[maxn],b[maxn];
int visa[30],visb[30];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		scanf("%s%s",a,b);
		for(int i=0;i<n;i++){
			visb[b[i]-'a']++;
			visa[a[i]-'a']++;
		}
		int flag=1;
		for(int i=0;i<25;i++){
			if(visb[i]>visa[i])flag=0;
			if(visb[i]%k==visa[i]%k){
				visa[i+1]+=visa[i]-visb[i];
			}
			else flag=0;
		}
		if(visb[25]!=visa[25])flag=0;
		for(int i=0;i<27;i++)visa[i]=0,visb[i]=0;
		if(flag)printf("Yes\n");
		else printf("No\n");
    }


    return 0;
}