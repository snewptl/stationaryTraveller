#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int mn[2],mx[2];
int ans[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i+=3){
			if(n-i+1<3)break;
			printf("? %d %d %d %d\n",1,i,i+1,n-1);
			fflush(stdout);
			scanf("%d",&mx[0]);
			printf("? %d %d %d %d\n",1,i,i+2,n-1);
			fflush(stdout);
			scanf("%d",&mx[1]);			
			printf("? %d %d %d %d\n",2,i+1,i,1);
			fflush(stdout);
			scanf("%d",&mn[0]);
			printf("? %d %d %d %d\n",2,i+2,i,1);
			fflush(stdout);
			scanf("%d",&mn[1]);		
			if(mx[0]==mx[1]){
				ans[i]=mx[0];ans[i+1]=mn[0];
				ans[i+2]=mn[1];
			}
			else if(mx[0]==mn[1]){
				ans[i]=mx[0];ans[i+1]=mn[0];
				ans[i+2]=mx[1];
			}
			else if(mn[0]==mx[1]){
				ans[i]=mn[0];ans[i+1]=mx[0];
				ans[i+2]=mn[1];
			}
			else if(mn[0]==mn[1]){
				ans[i]=mn[0];ans[i+1]=mx[0];
				ans[i+2]=mx[1];
			}
		}
		int ed=(n/3)*3;
		if(ans[ed]==n)ed--;
		for(int i=(n/3)*3+1;i<=n;i++){
			printf("? %d %d %d %d\n",1,ed,i,n-1);
			fflush(stdout);
			scanf("%d",&mx[0]);
			printf("? %d %d %d %d\n",2,i,ed,1);
			fflush(stdout);
			scanf("%d",&mn[0]);					
			if(mx[0]!=ans[ed])ans[i]=mx[0];
			else ans[i]=mn[0];
		}
		for(int i=1;i<=n;i+=3){
			if(ans[i]==1||ans[i]==2||ans[i]==n||ans[i]==n-1){
				printf("? %d %d %d %d\n",1,ed,i,n-1);
				fflush(stdout);
				scanf("%d",&mx[0]);
				printf("? %d %d %d %d\n",2,i,ed,1);
				fflush(stdout);
				scanf("%d",&mn[0]);					
				if(mx[0]!=ans[ed])ans[i]=mx[0];
				else ans[i]=mn[0];			
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");fflush(stdout);
    }


    return 0;
}