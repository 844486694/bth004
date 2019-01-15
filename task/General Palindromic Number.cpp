#include<iostream>
#include<string>

using namespace std;

int n,b;
int convert[100];
int main()
{
	scanf("%d%d",&n,&b);
	int index=0;
	bool flag=true;
	while(n!=0)
	{
		convert[index++]=n%b;
		n=n/b;	
	}
	for(int i=0;i<index/2;i++)
	{
		if(convert[i]!=convert[index-1-i])
		{
			flag=false;
			printf("No\n");
			break;
			
		}
	}	
	if(flag) printf("Yes\n");
	for(int i=index-1;i>=0;i--)
	{
		printf("%d",convert[i]);
		if(i!=0) printf(" ");
	}
	return 0;
}
