#include<iostream>
#include<string>
using namespace std;

int main(){
  int a,b,result,start=0;
  scanf("%d%d",&a,&b);
  result=a+b;
  string r=to_string(result);
  if(r[0]=='-')
    start=1;
    cout<<r[0];
  for(int i=start;i<r.length();i++)
  {
    int flag=r.length()-1-i;
    cout<<r[i];
    if(flag!=0&&flag%3==0)
    cout<<',';
  }
  return 0;
}
