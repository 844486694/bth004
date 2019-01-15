#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct table{
	int poptime,endtime,counter=0,vip=0;
};

struct player{
	int arrive,wait,vip,play;
};


bool cmp(player a,player b)
{
	return a.arrive<b.arrive;
}

vector<table> t;
vector<player> q;


int main()
{
	int n,k,m,cnt=1;
	scanf("%d",&n);
	q.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		int h,m,s,play;
		scanf("%d:%d:%d%d%d",&h,&m,&s,&q[i].play,&q[i].vip);
		q[i].arrive=3600*h+60*m+s;
		
	}
	
	sort(q.begin(),q.end(),cmp);
	
	scanf("%d",&k,&m);
	t.resize(k+1);

	for(int i=1;i<=m;i++)
	{
		int v;
		scanf("%d",&v);
		t[v].vip=1;
	}
	
	for(int i=1;i<=k;i++)
	{
		if(cnt<=n)
		{
			t[i].poptime=q[cnt].arrive+q[cnt].play;
			q[cnt].wait=0;
			cnt++;
			t[i].counter++;
		}
	}
	while(cnt<=n)
	{
		int avb=1,early=t[avb].poptime;
		
		for(int i=2;i<=n;i++)
		{
			if(early>t[i].poptime)
			{
				early=t[i].poptime;
				avb=i;
			}
		}
		if(t[avb].vip==1)
		{
			int vindex=-1;
			for(int i=cnt+1;i<=n;i++)
			{
				if(q[i].arrive<t[avb].poptime&&q[i].vip==1)
				{
					vindex=i;
					break;
				}
			}
			if(vindex!=-1)
			{
				player tmp=q[vindex];
				
				for(int i=vindex-1;i>=cnt;i--)
				{
					q[i+1]=q[i];					  
				}
				
				q[cnt]=tmp;
				q[cnt].wait=t[avb].poptime-q[cnt].arrive;
				t[avb].poptime+=q[cnt].play*60;

			}
			else
			{
				
				if(q[cnt].arrive<t[avb].poptime)
				{
					q[cnt].wait=t[avb].poptime-q[cnt].arrive;
					t[avb].poptime+=q[cnt].play*60;
				}
				
				else
				{
					q[cnt].wait=0;
					t[avb].poptime=q[cnt].arrive+q[cnt].play*60;
				}
			}
		}
		else
		{
			if(q[cnt].arrive<t[avb].poptime)
			{
				q[cnt].wait=t[avb].poptime-q[cnt].arrive;
				t[avb].poptime+=q[cnt].play*60;
			}
			else
			{
				q[cnt].wait=0;
				t[avb].poptime=q[cnt].arrive+q[cnt].play*60;
			}
		} 
		cnt++;
		t[avb].counter++;
	}
	sort(q.begin(),q.end(),cmp);
	for(int i=1;i<=n;i++)
	{
		int h,m,s,_h,_m,_s,wait;
		
		h=q[i].arrive/3600;
		m=(q[i].arrive%3600)/60;
		s=q[i].arrive%60;
		
		_m=q[i].wait+m;
		_h=h+_m/60;
		_s=s;
		_m=_m%60;
		wait=(q[i].wait%60<30)?(q[i].wait/60):(q[i].wait/60+1);
		if(_h<21)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",h,m,s,_h,_m,_s,wait);
			
		}
		
	}
	printf("%d",t[1].counter);
	for(int i=2;i<=k;i++)
	{
		printf(" %d",t[i].counter);	
	}
	return 0;
}
