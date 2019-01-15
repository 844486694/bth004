#include<iostream>
#include<algorithm>

using namespace std;

float poly[1001];
int main()
{
  fill(poly,poly+1001,0);
  int k,ex,cnt;
  float co;
  scanf("%d",&k);
  for(int i=0;i<k;i++)
  {
    scanf("%d%f",&ex,&co);
    poly[ex]+=co;
  }
  scanf("%d",&k);
  for(int i=0;i<k;i++)
  {
    scanf("%d%f",&ex,&co);
    poly[ex]+=co;
  }
  
  for(int i=0;i<1001;i++)
  {
    if(poly[i]!=0)cnt++;
  }
  printf("%d",cnt);
  for(int i=1000;i>=0;i--)
  {
    if(poly[i]!=0)
	{
		printf(" %d %.1f", i, c[i]);
	}
    
  }
  return 0;
}
