#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn];
int suma[maxn],sumb[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int flag=1,sgn=0;
        scanf("%d",&n);
		scanf("%s%s",s1,s2);
		for(int i=0;i<n;i++){
			a[i+1]=s1[i]-'0',b[i+1]=s2[i]-'0';
			suma[i+1]=suma[i],sumb[i+1]=sumb[i];
			if(a[i+1])suma[i+1]++;
			if(b[i+1])sumb[i+1]++;
		}
		for(int i=n;i>=1;i--){
			if(b[i]!=sgn?(a[i]^1):a[i]){
				if(suma[i]*2!=i)flag=0;
				sgn^=1;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}