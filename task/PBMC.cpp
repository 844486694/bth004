#include<iostream>
#include<vector>

using namespace std;
const int inf=9999999;
int weight[501],e[501][501],dis[501]={inf};
int minNeed=inf,minBack=inf;
bool visit[501]={false};
vector<int> pre[501];
vector<int> path,temppath;



void dfs(int v) {
  
    temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            // 自行车运回s0
            if(weight[id] > 0) {
                back += weight[id];
            } else {
              // 运来的自行车大于运回的自行车
                if(back > (0 - weight[id])) {
                    back += weight[id];
                }
                // 运来的自行车小于运来的自行车
                else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main()
{
	int c,n,d,r;
	fill(e[0],e[0]+501*501,inf);
	scanf("%d%d%d%d",&c,&n,&d,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&weight[i]);
		weight[i]=weight[i]-c/2;	
	}
	for(int i=0;i<r;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		e[x][y]=e[y][x]=t;	
	}
	dis[0]=0;	

	for(int i=1;i<=n;i++)
	{
		int index=-1,min=inf;
		for(int j=1;j<=n;j++)
		{
			if(visit[j]==false&&dis[i]<min)
			{
				index =j;
				min=dis[i];
			}
		}
		if(index==-1) break;
		visit[index]=true;
		for(int k=0;k<=n;k++)
		{
			if(visit[k==false&&e[index][k]!=inf])
			{
				if(dis[index]+e[index][k]<dis[k])
				{
					pre[k].clear();
					pre[k].push_back(index);
					dis[k]=dis[index]+e[index][k];
				}
				else if(dis[index]+e[index][k]==dis[k])
				{
					pre[k].push_back(index);
				}
			}
		}
	}
	dfs(d);
	    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
	return 0;
}
