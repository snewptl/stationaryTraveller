#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,p;
int mi[35];
int main(){
    scanf("%d%d",&n,&p);
	int i,flag=1;
	for(i=1;i<=30;i++){
		int temp=n-p*i;
		if(temp<=0){
			flag=0;
			break;
		}
		int cnt=0,x=temp;
		while(x){
			if(x&1)cnt++;
			x/=2;
		}
		if(temp>=i&&cnt<=i)break;
	}
	if(!flag)printf("-1\n");
	else printf("%d\n",i);
    return 0;
}