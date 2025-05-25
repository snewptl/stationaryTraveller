#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,q,l,r;
char a[maxn];
int sum[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%s",&n,&q,a);
		for(int i=0;i<=n;i++)sum[i]=0;
		int sgn;
		if(n%2)sgn=1;
		else sgn=-1;
		for(int i=n-1;i>=0;i--){
			int temp;
			if(a[i]=='+')temp=1;
			else temp=-1;
			sum[i]=temp*sgn+sum[i+1];
			sgn*=-1;
		}
		while(q--){
			scanf("%d%d",&l,&r);
			int temp=sum[l-1]-sum[r];
			if(temp==0)printf("0\n");
			else if(temp%2)printf("1\n");
			else printf("2\n");
		}

    }


    return 0;
}