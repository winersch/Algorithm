#include<stdio.h>
int n,m;
int visit[10]={0};
int arr[10]={0};

void dfs(int idx){
	if(idx==m){
		for(int i=0;i<m;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++){
			if(visit[i])
				continue;
			else{
				arr[idx]=i;
				visit[i]=1;
				dfs(idx+1);
				visit[i]=0;
			}
		}
	}
}
int main(void){
	scanf("%d %d",&n,&m);
	dfs(0);
	return 0;
}