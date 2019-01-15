#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string > DB;

int n,m;
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    string id,pwd;
    cin>>id>>pwd;
    int flag=0,len=pwd.length();
    for(int j=0;j<len;j++)
    {
      switch(pwd[j])
      {
        case '1': pwd[j]='@';flag=1;break;
        case '0': pwd[j]='%';flag=1;break;
        case 'l':pwd[j]='L';flag=1;break;
        case 'O':pwd[j]='o';flag=1;break;
      }
    }
    if(flag==1)
    {
       DB.push_back(id+" "+pwd);
 
    }
  }
    int cnt = DB.size();
    if(cnt != 0) {
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++)
            cout << DB[i] << endl;
    } else if(n == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", n);
      
    }
    
  return 0;
}