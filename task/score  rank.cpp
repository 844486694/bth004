#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class student
{
public:
	int id,index=-1;
	int score[4];
	int rank[4]; 		
};
int exist[1000000]={0};
int n,m,c,m,e,flag=0,id;
vector<student> stus;
char list[4]={'A','C','M','E',};
bool cmp(student s1,student s2)
{
	return (s1.score[flag]>s2.score[flag]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		student s;
		cin>>id>>c>>m>>e;
		s.id=id;
		s.score[0]=(c+m+e)/3;
		s.score[1]=c;
		s.score[2]=m;
		s.score[3]=e;
		stus.push_back(s); 
	}
	for(flag=0;flag<4;flag++)
	{
		sort(stus,stus+n,cmp);
		stus[0].rank[flag]=1;
		for(int i=1;i<n;i++)
		{
			stus[i].rank[flag]=i+1;
			if(stus[i].score[flag]==stus[i-1].score[flag])
				stus[i].rank[flag]=stus[i-1].rank[flag];

		}
	}
	for(int i=0;i<n;i++)
	{
		exist[stus[i].id]=i+1;
		stus[i].index=0;
		int m=stus[i].rank[0];
		for(int j=1;j<4;j++)
		{
			if(stus[i].rank[j]<m)
			{
				m=stus[i].rank[j];
				stus[i].index=j;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>id;
		if(exist[id])
			cout<<stus[exist[id]-1].rank[index]<<' '<<list[stus[exist[id]-1].rank[index]]<<endl;
		else
			cout<<"N/A"<<endl;
			
	}
	return 0;
}

