#include<iostream>

using namespace std;

float poly[2002]={0.0};
float p1[1001]={0.0};
int k,n,cnt=0;
float a;

int main()
{
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%f",&n,&a);
		p1[n]=a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%f",&n,&a);
		for(int j=0;j<1001;j++)
		{
			poly[j+n]+=p1[j]*a;
		}
	}
	
	for(int i=0;i<2002;i++)
	{
		if(poly[i]!=0)cnt++;
	}
	cout<<cnt;
	for(int i=2001;i>=0;i--)
	{
		if(poly[i]!=0)
		{
			printf(" %d %.1f",i,poly[i]);
		}
	}
	return 0;
}
