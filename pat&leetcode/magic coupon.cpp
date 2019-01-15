#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> c,b;
int n,m;
int main()
{
  int ans=0;
  cin>>n;
  c.resize(n);
  for(int i=0;i<n;i++)
  {
    int input;
    cin>>input;
    c[i]=input;
  }
  cin>>m;
  b.resize(m);
  for(int i=0;i<m;i++)
  {
    int input;
    cin>>input;
    b[i]=input;
  }
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  int x=0,y=0;

  while(x<n&&y<m&&c[x]<0&&b[y]<0)
  {
    ans+=c[x]*b[y];
    x++,y++;
  }
  x=n-1;
  y=m-1;
  while(x>=0&&y>=0&&c[x]>0&&b[y]>0)
  {
    ans+=c[x]*b[y];
    x--,y--;
  }
  cout<<ans;
  return 0;
  
}