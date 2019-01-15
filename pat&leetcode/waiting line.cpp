#include<iostream>
#include<queue>
#include<vector>
#define h 60

using namespace std;

class windows
{
	public:
	int poptime=0,endtime=0;
	queue<int> q;
};



int customerCnt=1,n,m,k,q,t;
vector<windows> w(21);
int time[1001];
int result[1001]={0}; 
bool sorry[1001]={false};

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&time[i]);
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(customerCnt<=k)
			{
				
				w[i].q.push(time[customerCnt]);
				
				if(w[i].endtime>=8*h)
				{
					sorry[customerCnt]=true;
				}
				
				if(j==1)
				{
					w[i].poptime=w[i].endtime;
				}
				result[customerCnt]=w[i].endtime;
				customerCnt++;
				
			}
		}
	}
	while(customerCnt<=k)
	{
		int choice=1,minend=w[choice].poptime;
		for(int i=2;i<=n;i++)
		{
			if(w[i].poptime<minend)
			{
				choice=i;
				minend=w[i].poptime;
			}
		}
		w[choice].q.pop();
		w[choice].q.push(time[customerCnt]);
		w[choice].poptime+=w[choice].q.front();
		if(w[choice].endtime>=8*h)
		{
			sorry[customerCnt]=true;
		}
		w[choice].endtime+=time[customerCnt];
		result[customerCnt]=w[choice].endtime;
		customerCnt++;
	}
	for(int i=0;i<q;i++)
	{
		cin>>t;
		if(sorry[t])cout<<"Sorry"<<endl;
		else printf("%02d:%02d\n",time[t]/60+8,time[t]%60);
	}
	return 0;
}
