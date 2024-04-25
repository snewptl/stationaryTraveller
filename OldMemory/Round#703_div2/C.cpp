#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,pos,ans;
void findle(int l,int r){
	if(l>r)return;
	int mid=l+r>>1,le;
	printf("? %d %d\n",mid,pos);
	fflush(stdout);
	scanf("%d",&le);
	if(le==pos){
		ans=max(ans,mid);findle(mid+1,r);
	}	
	else findle(l,mid-1);
}
void findri(int l,int r){
	if(l>r)return;
	int mid=l+r>>1,ri;
	printf("? %d %d\n",pos,mid);
	fflush(stdout);
	scanf("%d",&ri);
	if(ri==pos){
		ans=min(ans,mid);findri(l,mid-1);
	}
	else findri(mid+1,r);
}
int main(){
	int le=0,ri=0;
    scanf("%d",&n);
	printf("? %d %d\n",1,n);
	fflush(stdout);
	scanf("%d",&pos);
	if(pos!=1){
		printf("? %d %d\n",1,pos);
		fflush(stdout);
		scanf("%d",&le);		
	}
	if(pos!=n){
		printf("? %d %d\n",pos,n);
		fflush(stdout);
		scanf("%d",&ri);		
	}
	if(le==pos){
		ans=0;findle(1,pos-1);
	}
		
	else {
		ans=n+1;findri(pos+1,n);
	}
	printf("! %d\n",ans);
	fflush(stdout);	
    return 0;
}