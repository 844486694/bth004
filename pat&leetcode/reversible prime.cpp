#include<iostream>
#include<cmath>
using namespace std;


bool isprime(int n)
{
	if(n<=1)return false;
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0)return false; 
	} 
	return true;
}
int main()
{
	int n,d;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)break;
		scanf("%d",&d);
		if(isprime(n)==false)
		{
			printf("No\n");
			continue;
		}
		int index=0,reverse=0,arr[100000]={0};
		while(n!=0)
		{
			arr[index++]=(n%d);
			n/=d;
		}
		
		for(int i=0;i<index;i++)
		{
			reverse=reverse*d+arr[i];
		}
		if(isprime(reverse)==true)printf("Yes\n");
		else printf("No\n");
	}	
	return 0;
}
