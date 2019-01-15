#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,id,k,subid,maxdepth=0;
vector<int> tree[100];
int depth[100]={0};
void dsf(int index,int d)
{
	if(tree[index].size()==0)
	{
		depth[d]++;
		maxdepth=max(d,maxdepth);
		return ;
	}
	for(int i=0;i<tree[index].size();i++)
	{
		dsf(tree[index][i],d+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&subid);
			tree[id].push_back(subid);
		}
	}
	dsf(0,0);
	for(int i=0;i<maxdepth;i++)
	{
		printf("%d",depth[i]);
		if(i!=maxdepth-1) printf(" ");
		
		
	}
	return 0;
}
