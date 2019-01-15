#include<iostream>

using namespace std;
const int up=6,down=4,stay=5;
int n,f=0,cnt=0,dest;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&dest);
		if(dest>f)
		{
			cnt+=5+(dest-f)*up;
		}
		else 
		{
			cnt+=5+(f-dest)*down;
		}
		f=dest;
	}
	cout<<cnt;
	return 0;
}
