#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int _max=0,depth[10001];
bool visit[10001];
int n,component=0;
vector<int> edge[10001];
void dfs1(int index)
{
	visit[index]=true;
	int len=edge[index].size();
	for(int i=0;i<len;i++)
	{
		if(visit[edge[index][i]]==false)
		{
			dfs1(edge[index][i]);
		}
	}
}
void dfs2(int index,int height)
{
	_max=max(_max,height);
	visit[index]=true;
	int len=edge[index].size();
	for(int i=0;i<len;i++)
	{
		if(visit[edge[index][i]]==false)
		{
			dfs2(edge[index][i],height+1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	fill(visit,visit+10000,false);
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==false)
		{
			dfs1(i);
			component++;
		}
	}
	if(component>1)
	{
		printf("Error: %d components\n",component);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			fill(visit,visit[10001],false);
			_max=0;
			dfs2(i,1);
			depth[i]=_max;	
		}
		for(int i=1;i<=n;i++)
		{
			_max=max(_max,depth[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(depth[i]==_max)
			cout<<i<<endl;
		}
	}
	
	
	return 0;
}
