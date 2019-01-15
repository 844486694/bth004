#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,vector<int>> r;

int q,c,id,m;

int main()
{
  cin>>q>>c;
  for(int i=0;i<c;i++)
  {
    cin>>id>>m;
    string name;
    for(int j=0;j<m;j++)
    {
      cin>>name;
      r[name].push_back(id);
    }
  }
  for(int i=0;i<q;i++)
  {
    string name;
    
    cin>>name;
    int size=r[name].size();
    cout<<name<<" "<<size;
    sort(r[name].begin(),r[name].end());
    for(int j=0;j<size;j++)
    {
      printf(" %d",r[name][j]);
    }
    cout<<endl;
  }
}