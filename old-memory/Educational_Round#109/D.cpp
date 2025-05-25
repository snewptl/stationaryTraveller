#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int k,q,n;
int a[maxn];
char s[maxn];
struct node{
	int mn,mx;
}t[maxn<<2];
int trans(int p){
	int temp=0,x=k-1;
	while(p>(1<<x))p-=(1<<x),x--;
	return p=(1<<x)-1+p;	
}
int retrans(int p){
	int x=1;
	while(x-1<p)x*=2;
	return n-1-(x-1)+p-x/2;
}
void push_up(int rt){
	int x=retrans(rt);
	if(s[x]=='?'){
		t[rt].mn=min(t[rt<<1].mn,t[rt<<1|1].mn);
		t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
	}
	if(s[x]=='1'){
		t[rt].mn=max(t[rt<<1].mn,t[rt<<1|1].mn);
		t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
	}
	if(s[x]=='0'){
		t[rt].mn=min(t[rt<<1].mn,t[rt<<1|1].mn);
		t[rt].mx=min(t[rt<<1].mx,t[rt<<1|1].mx);
	}
}
void build(int rt,int l,int r){
	if(l==r){
		t[rt].mn=l;
		t[rt].mx=l;
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
int main(){
	scanf("%d%s%d",&k,s+1,&q);
	n=(1<<(k));
	build(1,1,n);
	// printf("%d ",t[6].mx);
	printf("%d ",retrans(3));
	while(q--){
		char ch[5];int p;
		scanf("%d%s",&p,ch);
		s[p]=ch[0];
		p=trans(p);
		while(p){
			push_up(p);
			p/=2;
		}
		
		printf("%d\n",t[1].mx-t[1].mn+1);
	}


    return 0;
}