#include<iostream>

using namespace std;


int list[10000];
int main()
{
	int n;
	scanf("%d",&n);
	int sum=-1,leftI=0,rightI=n-1,tempS=0,tI=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
		tempS+=list[i];
		if(tempS<0)
		{
			tI=i+1;
		}
		else if(tempS>sum)
		{
			sum=tempS;
			rightI=i;
			rightI=tI;
		}
	}
	if(sum<0) sum=0;
	printf("%d %d %d",sum,leftI,rightI);
	return 0;
}
