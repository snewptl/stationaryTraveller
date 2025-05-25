#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,ans;
int opt[maxn],pos[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
       ans=0;scanf("%d",&n);
	   for(int i=1;i<=n;i++){
		   scanf("%d%d",&opt[i],&pos[i]);
	   }
	   int t=0,p=0,curt=0,curp=0,val=0,vec=0;
	   opt[n+1]=2e9+10;
	   for(int i=1;i<=n;i++){
			if(t<opt[i])t=opt[i];
			val=abs(pos[i]-p);
			curt=t,curp=p;
			t+=val,p=pos[i];
			if(p>curp)vec=1;
			else vec=-1;
			if(t<=opt[i+1])ans++;
			printf("%d\n",ans);
			while(i+1<=n&&opt[i+1]<t){
				int st=(opt[i+1]-curt)*vec+curp;
				int ed=(opt[i+2]-curt)*vec+curp;
				if(st<=pos[i+1]&&ed>=pos[i+1])ans++;printf("%d\n",ans);
				i++;
			}
			
	   } 
	   printf("%d\n",ans);
    }


    return 0;
}