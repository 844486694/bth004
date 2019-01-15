#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct record
{
  int local_rank,final_rank,location,score;
  long long id;
};
bool cmp(record a, record b)
{
  return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int n,m;
vector<record> final;

int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&m);
    vector<record>local(m);
    for(int j=0;j<m;j++)
    {
      scanf("%lld%d",&local[j].id,&local[j].score);
      local[j].location=i+1;
    }
    sort(local.begin(),local.end(),cmp);
    local[0].local_rank=1;
    final.push_back(local[0]);
    for(int j=1;j<m;j++)
    {
      
      if(local[j].score==local[j-1].score)local[j].local_rank=local[j-1].local_rank;
      else local[j].local_rank=j+1;
      final.push_back(local[j]);
    }
  }
  int size=final.size();
  cout<<size<<endl;
  sort(final.begin(),final.end(),cmp);
  final[0].final_rank=1;
  for(int i=1;i<size;i++)
  {
    if(final[i].score==final[i-1].score)
    {
      final[i].final_rank=final[i-1].final_rank;
      
    }
    else final[i].final_rank=i+1;
  }
  for(int i=0;i<size;i++)
  {
    cout<<final[i].id<<' '<<final[i].final_rank<<' '<<final[i].location<<" "<<final[i].local_rank<<endl;
    
  }
  return 0;
}