#include<iostream>

using namespace std;

string input;
int n1,n2,m=0,t;
int main()
{
  cin>>input;
  int l=input.length();
  for(t=3;t<=l;t++)
  {
    n1=(l+2-t)/2;
    
    if(n1>=m&&n1<=t)
    {
		m=n1;
		n2=t;
    }
  }
    cout<<"n1:"<<m<<" n2:"<<n2<<" "<<l<<endl;;
  int index=0;
  for(;index<m-1;index++)
  {
    printf("%c",input[index]);
    for(int i=0;i<n2-2;i++)
      printf(" ");
    printf("%c",input[l-index-1]);
    printf("\n");
  }
//  cout<<endl;
  for(;index<l-m+1;index++)
  {
    printf("%c",input[index]);
  }
  

  return 0;
}
