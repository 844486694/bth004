#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;

int loc[55];
bool visit[55];
string init[55];

void dfs(int tindex,string ex)
{
  if(visit[tindex]=true)return ;
  visit[tindex]=true;
  
  int nindex=loc[tindex];
  //string nstr=init[tindex];
   
  init[tindex]=ex;
  dfs(nindex,nstr);
}


int main()
{
  //init
  for(int i=0;i<4;i++)
  {
    for(int j=1;j<14;j++)
    {
      string t;
      switch(i)
      {
        case 0:t="S";break;
        case 1:t="H";break;
        case 2:t="C";break;
        case 3:t="D";break;
      }
      init[i*13+j]=t+to_string(j);
    }
  }
  init[53]="J1";
  init[54]="J2";
  
  //init
  int n;
  
  scanf("%d",&n);
  for(int i=1;i<=54;i++)
  {
    scanf("%d",&loc[i]);
  }
  
  for(int i=0;i<n;i++)
  {
    fill(visit,visit+55,false);
    for(int j=1;j<=54;j++)
    {
    	if(visit[j]==false)
    	{
    		string s=init[j];
      		dfs(loc[j],s);
		}

    }
  }
  
  cout<<init[1];
  for(int i=2;i<=54;i++)
    cout<<" "<<init[i];
  return 0;
}
