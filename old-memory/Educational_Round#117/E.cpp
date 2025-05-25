#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
struct node{
	int m,k,idx;
}stu[maxn];
bool cmp(node a,node b){
	return a.k<b.k;
}
double val[maxn];
double pre[maxn];
double ans;
int pos;
double f(int x){
	for(int i=1;i<=n;i++)pre[i]=val[i]=0.0;
	for(int i=1;i<=n;i++){
		int k=stu[i].k,m=stu[i].m;
		if(k<=x){
			pre[m]+=k;
		}
		else val[m]+=1;
	}
	for(int i=1;i<=2e5;i++){
		val[i]+=pre[i]/x;
	}
	sort(val+1,val+200001);
	double res=0;
	for(int i=1;i<=x;i++){
		res+=val[i];
	}
	return res;
}
vector<pair<double,int>>vec;
void print(){
	vec.clear();
	for(int i=1;i<=n;i++)pre[i]=val[i]=0.0;
	for(int i=1;i<=n;i++){
		int k=stu[i].k,m=stu[i].m;
		if(k<=pos){
			pre[m]+=k;
		}
		else val[m]+=1;
	}
	for(int i=1;i<=2e5;i++){
		val[i]+=pre[i]/pos;
		vec.push_back({val[i],i});
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<pos;i++){
		printf("%d ",vec[i].second);
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<+n;i++)pre[i]=0.0;
		for(int i=1;i<=n;i++){
			int m,k,idx;
			scanf("%d%d",&m,&k);
			idx=i;
			stu[i]={m,k,idx};
		}
		sort(stu+1,stu+n+1,cmp);
		int l=1,r=2e5;
		while(true){//精
			int len=(r-l)/3;
			int m1 = l + len,m2 = min(r,l+ 2*len);
			double res1=f(m1),res2=f(m2);
			if(res1<res2)
				l = m1;
			else
				r = m2;
			if(len==0)break;
		}
		for(int i=l;i<=r;i++){
			double res=f(i);
			if(ans<res){
				ans=res;
				pos=i;
			}
		}
		print();


	}


	return 0;
}