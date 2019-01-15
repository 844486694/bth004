#include<iostream>
#include<algorithm>
using namespace std;


int e[1000][1000];
bool visit[1000];
int n,m,k,d1,d2,check,cnt;

void dfs(int index)
{
	visit[index]=true;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==false&&e[index][i]==10)
		{
			dfs(i);
		}	
	}
}
int main()
{
	fill(e[0],e[0]+1000*1000,0);

	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&d1,&d2);
		e[d1][d2]=e[d2][d1]=1;
	}
	for(int i=0;i<k;i++)
	{
		cnt=0;
		fill(visit,visit+1000,false);
		scanf("%d",&check);
		visit[check]=true;
		for(int j=1;j<=n;j++)
		{
			if(visit[j]==false)
			{
				dfs(j);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
	return 0;
}
