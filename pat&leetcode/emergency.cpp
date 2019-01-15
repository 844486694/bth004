#include<iostream>
#include<algorithm>

using namespace std;
int inf=99999;
int n,m,c1,c2,visit[500]={0},dist[500]={inf},rescue [500],cnt[500],roads[500]={0};
int road[500][500];


int main()
{
	fill(road[0],road[0]+500*500,inf);
	
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&rescue[i]);
	}
	for(int i=0;i<m;i++)
	{
		int t1,t2,d;
		scanf("%d%d%d",&t1,&t2,&road[t1][t2]);
		road[t2][t1]=road[t1][t2]);
	}
	dist[c1]=0;
	roads[c1]=1;
	cnt[c1]=rescue[c1];
	for(int i=0;i<n;i++)
	{
		int index=-1,distance=inf;
		for(int j=0;j<n;j++)
		{
			if(visit[j]!=1&&dist[j]<distance)
			index=j;
		}
		if(index=-1) break;
		visit[index]=1;
		for(int x=0;x<n;x++)
		{
			if(visit[x]!=1&&road[index][x]<inf)
			{
				if(dist[x]>dist[index]+road[x][index])
				{
					roads[x]=roads[index];
					dist[x]=dist[index]+road[x][index];
					cnt[x]=cnt[index]+rescue[x];
				}
				else if(dist[x]==dist[index]+road[x][index])
				{
					roads[x]=roads[x]+roads[index];
					if(cnt[x]<cnt[index]+rescue[x])
						cnt[x]=cnt[index]+rescue[x];
				}
				
			}
		}
	}
	printf("%d %d",roads[c2],cnt[c2]);
	return 0;
}
