#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,sum;
int a[maxn],r[maxn];
char s[maxn],up[maxn],dn[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		scanf("%s",s);
		for(int i=1;i<=n;i++)a[i]=s[i-1]-'0';
		int flag=0,pos=0;
		for(int i=n;i>=1;i--){
			if(!a[i]){
				if(pos)if((pos-i-1)%2!=0)flag=1;
				r[i]=pos,pos=i;
				sum++;
				// printf("%d ",r[i]);
			}
		}
		if(a[1]!=1||a[n]!=1)flag=1;
		if(sum%2!=0)flag=1;
		if(flag)printf("NO\n");
		else {
			printf("YES\n");
			up[1]=dn[1]='(';
			dn[n]=up[n]=')';
			if(pos%2){
				up[2]=dn[2]='(';
				dn[n-1]=up[n-1]=')';
				for(int i=3;i<pos;i++){
					if(i%2){
						up[i]=dn[i]=')';
						dn[n-i+1]=up[n-i+1]='(';						
					}
					else {
						up[i]=dn[i]='(';
						dn[n-i+1]=up[n-i+1]=')';								
					}
				}
			}
			else {
				for(int i=2;i<pos;i++){
					if(i%2==0){
						up[i]=dn[i]='(';
						dn[n-i+1]=up[n-i+1]=')';						
					}
					else {
						up[i]=dn[i]=')';
						dn[n-i+1]=up[n-i+1]='(';								
					}
				}
			}
			int cnt=0;
			for(int i=pos;i;i=r[i]){
				if(cnt%2==0){
					up[i]=')';dn[i]='(';
				}
				else up[i]='(',dn[i]=')';
				for(int j=i+1;j<r[i];j++){
					if((j-i-1)%2==0)up[j]=dn[j]='(';
					else up[j]=dn[j]=')';
				}
				cnt++;
			}

			if(sum==0){
				for(int i=1;i<=n;i++){
					if(i%2)up[i]=dn[i]='(';
					else up[i]=dn[i]=')';
				}
			}			
			for(int i=1;i<=n;i++)printf("%c",up[i]);
			printf("\n");
			for(int i=1;i<=n;i++)printf("%c",dn[i]);
			printf("\n");

		}
		for(int i=1;i<=n;i++)r[i]=0;
    }


    return 0;
}

