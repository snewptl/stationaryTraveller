#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
int a[maxn],b[maxn];
int ans1,ans2;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans1=0,ans2=0;
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		int mida=0,midb=0;
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				mida++;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]<0){
				midb++;
			}
		}
		if(mida&&midb){
			int lb=1,rb=1,la=1;
			while(a[la]<b[lb])la++;
			int num=mida-la+1,temp=0;
			if(la<=mida){
				while(abs(b[rb]-b[lb])+1<=num&&rb<=midb)rb++;
				rb--;temp=rb-lb+1;ans1=temp;
				rb++;
				for(;rb<=midb;rb++){
					temp++;
					while(abs(b[rb]-b[lb])+1>num){
						if(num<=0)break;
						if(a[la]!=b[lb])temp--;
						lb++;
						while(a[la]<b[lb]){
							la++,num--;
							if(num<=0)break;
						}
					}
					if(num<=0)break;
					ans1=max(temp,ans1);
					
				}					
			}
		}
		if(mida!=n&&midb!=m){
			int rb=m,lb=m,ra=n;
			while(a[ra]>b[rb])ra--;
			int num=ra-mida,temp=0;
			if(ra>mida){
				while(b[rb]-b[lb]+1<=num&&lb>midb)lb--;
				lb++;temp=rb-lb+1;ans2=temp;
				lb--;
				for(;lb>midb;lb--){
					temp++;
					while(b[rb]-b[lb]+1>num){
						if(num<=0)break;
						if(a[ra]!=b[rb])temp--;
						rb--;
						while(a[ra]>b[rb]){
							ra--,num--;
							if(num<=0)break;
						}
					}
					if(num<=0)break;
					ans2=max(temp,ans2);
					
				}
			}
		}
		printf("%d\n",ans1+ans2);

    }


    return 0;
}