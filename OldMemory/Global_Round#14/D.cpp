#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,l,r;
int a[maxn],b[maxn];
int c[maxn];
int ans,temp1,temp2;
int sgn1,sgn2;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&l,&r);
		ans=temp1=temp2=0;
		sgn1=sgn2=0;
		for(int i=1;i<=n;i++)c[i]=0;
		for(int i=1;i<=l;i++){
			scanf("%d",&a[i]);
			c[a[i]]++;
		}
		for(int i=1;i<=r;i++){
			scanf("%d",&b[i]);
			c[b[i]]--;
		}
		for(int i=1;i<=n;i++){
			if(c[i]<0)temp1+=abs(c[i]);
			if(c[i]>0)temp2+=abs(c[i]);
		}
		for(int i=1;i<=n;i++){
			if(c[i]%2!=0){
				if(c[i]<0)sgn1++;
				else sgn2++;
			}
		}
		if(sgn1>sgn2){
			if(sgn1<=temp2)ans+=(temp1+temp2)/2;
			else ans+=sgn1+(temp1-sgn1)/2;
		}
		else {
			if(sgn2<=temp1)ans+=(temp1+temp2)/2;
			else ans+=sgn2+(temp2-sgn2)/2;
		}
		printf("%d\n",ans);
    }


    return 0;
}