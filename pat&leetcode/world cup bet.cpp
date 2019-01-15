#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char list[3]={'W','T','L'};
int dist[3];
float maxO=1,temp;
vector<float> odd[3];
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%f",&temp);
			odd[i].push_back(temp);
		}
	}
	for(int i=0;i<3;i++)
	{
		maxO*=*max_element(odd[i].begin(),odd[i].end());
		dist[i]=distance(odd[i].begin(),max_element(odd[i].begin(),odd[i].end()));
	}
	maxO=(maxO*0.65-1)*2;
	for(int i=0;i<3;i++)
	{
		cout<<list[dist[i]]<<" ";
	}
	printf("%.2f",maxO); 
	return 0;	
}
