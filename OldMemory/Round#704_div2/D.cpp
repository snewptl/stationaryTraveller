#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int m[maxn],n[maxn];
int a,b,k;
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(k==0){
		printf("Yes\n");
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");
		printf("\n");
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");		
		printf("\n");
	}
	else if(a==0){
		if(k!=0)printf("No\n");
		else {
			printf("Yes\n");
			for(int i=1;i<=a+b;i++)printf("1");
			printf("\n");
			for(int i=1;i<=a+b;i++)printf("1");
			printf("\n");				
		}
	}
	else if(b==1){
		if(k!=0)printf("No\n");
		else {
			printf("Yes\n");
			printf("1");
			for(int i=1;i<a+b;i++)printf("0");
			printf("\n");
			printf("1");
			for(int i=1;i<a+b;i++)printf("0");
			printf("\n");			
		}
	}
	else if(k>a+b-2)printf("No\n");
	else {
		int flag=0;
		for(int i=1;i<=b-1;i++){
			m[a+b-i+1]=n[a+b-i+1]=1;
			if(a+b-i+1==k+1)flag=1;
		}
		if(flag)m[a+1]=n[a+1]=1;
		m[k+1]=1,n[k+1]=0;
		m[1]=0,n[1]=1;
		printf("Yes\n");
		for(int i=a+b;i>=1;i--)printf("%d",m[i]);
		printf("\n");
		for(int i=a+b;i>=1;i--)printf("%d",n[i]);
		printf("\n");
	}

    return 0;
}