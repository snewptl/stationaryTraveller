#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn],c[maxn],d[maxn];
pii seg[maxn*30];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        int head=1,tail=0,ans=0;
        seg[++tail]={1,n};
        for(int i=29;i>=0;i--){
            int cur=1<<i,flag=1;
            for(int j=head;j<=tail;j++){
                int cnt0=0,cnt1=0;
                for(int k=seg[j].first;k<=seg[j].second;k++){
                    if(a[k]&cur)cnt0++;
                    if(b[k]&cur)cnt1++;
                }
                if(cnt0+cnt1!=seg[j].second-seg[j].first+1)flag=0;
            }
            if(flag){
                ans+=cur;
                int lst=tail;
                for(int j=head;j<=lst;j++){
                    int len1=0,len2=0;
                    for(int k=seg[j].first;k<=seg[j].second;k++){
                        if(a[k]&cur)c[++len1]=a[k];
                        else d[++len2]=a[k];
                    }
                    if(len1)seg[++tail]={seg[j].first,len1+seg[j].first-1};
                    if(len2)seg[++tail]={len1+seg[j].first,seg[j].second};
                    for(int k=seg[j].first;k<=seg[j].second;k++){
                        if(len1)a[k]=c[len1--];
                        else a[k]=d[len2--];
                    }

                     for(int k=seg[j].first;k<=seg[j].second;k++){
                        if((b[k]&cur)==0)c[++len1]=b[k];
                        else d[++len2]=b[k];
                    }
                    for(int k=seg[j].first;k<=seg[j].second;k++){
                        if(len1)b[k]=c[len1--];
                        else b[k]=d[len2--];
                    }                  
                }
                head=lst+1;
            }
        }
        printf("%d\n",ans);
	}


	return 0;
}