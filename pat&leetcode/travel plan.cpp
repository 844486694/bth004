#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int inf=999999;
int dist[501],edge[501][501],cost[501][501];
int n,m,s,d,mincost=inf;
bool visit[501]={false};

vector<int> pre[501];
vector<int> tp,p;

void minpath(int index)
{
	tp.push_back(index);
	if(index==s)
	{
		int tc=0;


		for(int x=tp.size()-1;x>0;x--)
		{
			int id=tp[x], next=tp[x-1];
			tc+=cost[id][next];
			
		}
		if(tc<mincost)
		{
			mincost=tc;
			p=tp;
		}
		tp.pop_back();
		return ;
	}
	else
	{
		int size=pre[index].size();
		for(int x=0;x<size;x++)
		{
			minpath(pre[index][x]);
		}
	}
	tp.pop_back();
}

int main()
{
	fill(edge[0],edge[0]+501*501,inf);
	fill(dist,dist+501,inf);
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=0;i<m;i++)
	{
		int c1,c2,l,c;
		scanf("%d%d%d%d",&c1,&c2,&l,&c);
		edge[c1][c2]=edge[c2][c1]=l;
		cost[c1][c2]=cost[c2][c1]=c;
	}
	pre[s].push_back(s);
	dist[s]=0;

	for(int i=0;i<n;i++)
	{
		int index=-1,min=inf;
		for(int j=0;j<n;j++)
		{
			if(dist[j]<min&&visit[j]==false)
			{
				min=dist[j];
				index=j;
			}
		}	
		if(index==-1) break;
		visit[index]=true;
		for(int x=0;x<n;x++)
		{
			if(visit[x]==false&&edge[x][index]<inf)
			{
				if(dist[x]>dist[index]+edge[x][index])
				{
					dist[x]=dist[index]+edge[x][index];
					pre[x].clear();
					pre[x].push_back(index);
				}
				else if(dist[x]==dist[index]+edge[x][index])
				{
					pre[x].push_back(index);
				}
			}	
		}	
	}
	minpath(d);
	int len=p.size();
	for(int i=len-1;i>=0;i--)
	{
		printf("%d ",p[i]);

	}
	printf("%d %d",dist[d],mincost);

	return 0;
}
