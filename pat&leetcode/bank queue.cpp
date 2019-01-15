#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class window{
public:
	int endtime;
};
class client
{
public:
	int arrive,wait,p;
	
};
int n,k,h,m,s,p;
bool cmp(client a,client b)
{
	return a.arrive<b.arrive;
}
int main()
{
	scanf("%d%d",&n,&k);
	vector<window> w(k);
	vector<client> c(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d:%d%d",&h,&m,&s,&p);
		c[i].p=p*60;
		c[i].arrive=h*3600+m*60+s;
	}
	sort(c.begin(),c.end(),cmp);
	int cnt=0;
	for(int i=0;i<k;i++)
	{
		if(cnt<n)
		{
			c[i].wait=0;
			w[i].endtime=c[i].arrive+c[i].p;
			cnt++;
		}
		
	}
	while(cnt<n)
	{
		int index=0,minend=w[index].endtime;
		for(int i=1;i<k;i++)
		{
			if(w[i].endtime<minend)
			{
				index=i;
				minend=w[i].endtime;
			}
		}
		if(c[cnt].arrive<w[index].endtime)
		{
			c[cnt].wait=w[index].endtime-c[cnt].arrive;
			w[index].endtime+=c[cnt].p;
		}
		else
		{
			c[cnt].wait=0;
			w[index].endtime=c[cnt].arrive+c[cnt].p;
		}
		cnt++;
	}
	float mean=0;
	for(int i=0;i<n;i++)
	{
		mean+=c[i].wait; 
	}
	printf("%.1f",((mean*1.0)/60)/n);
	return 0;
}
