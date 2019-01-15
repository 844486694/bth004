#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> final;
int list[300500];

int main()
{
  int n,m,t;
  int cnt=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&t);
    // final.push_back(t);
    list[cnt++]=t;
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d",&t);
    // final.push_back(t);
        list[cnt++]=t;
  }
  
  // sort(final.begin(),final.end());
  sort(list,list+(cnt));
  // int size=final.size();
  printf("%d",list[(cnt-1)/2]);
  
  
  
  return 0;

  
  
}