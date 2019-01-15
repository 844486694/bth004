#include<iostream>
#include<climits>
using namespace std;

int n,sh,smin,ss,eh,emin,es,unlocktime=INT_MAX,locktime=INT_MIN;
string lock,unlock,id;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int s,e;
		cin>>id;
		scanf("%d:%d:%d %d:%d:%d",&sh,&smin,&ss,&eh,&emin,&es);
		s=3600*sh+60*smin+ss;
		e=3600*eh+60*emin+es;

		if(s<unlocktime)
		{
			unlocktime=s;
			unlock=id;
		}
		if(e>locktime)
		{
			locktime=e;
			lock=id;
		}

	}	
	cout<<unlock<<" "<<lock;
	return 0;
}
