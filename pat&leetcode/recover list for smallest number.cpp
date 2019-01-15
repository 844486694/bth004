#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> s;
bool cmp(string a,string b)
{
  return a+b<b+a;
}
int main()
{
  string ans;
  int n;
  cin>>n;
  s.resize(n);
  for(int i=0;i<n;i++)
  {
    string t;
    cin>>t;
    s[i]=t;
  }
  sort(s.begin(),s.end(),cmp);
  
  for(auto it=s.begin();it!=s.end();it++)
  {
    ans+=*it;
  }
  
  //首部有许多0!!!!
  while(ans.length() != 0 && ans[0] == '0')
      ans.erase(ans.begin());
  //首部有许多0!!!!    
      
  if(ans.length() == 0) cout << 0;
  cout<<ans;
  return 0;
}