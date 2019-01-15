#include<iostream>
#include<vector>
#include<cmath>



using namespace std;



struct node{
  string id,name;
  int score;
};
vector<node> m,f;
bool cmp(node a,node b)
{
  return a.score<b.score;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    node t;
    char g;
    int s;
    string id,name;
    cin>>name>>g>>id>>s;

    t.id=id;
    t.score=s;
    t.name=name;
//        cout<< t.name<<" "<< g<<" "<<t.id <<" "<<t.score<<endl;;
//    scanf("%s %c %s %d",&t.name,&g,&t.id,&t.score);
    if(g=='F')f.push_back(t);
    else if(g=='M')m.push_back(t);
  }
  int lM=m.size(),lF=f.size();
//  cout<<"LM: "<<lM<<" LF:"<<lF<<endl;
  if(lF==0)
  {  
	int index=0;
	for(int i=1;i<lM;i++)
	{
		if(m[i].score<m[index].score)
			index=i;
	}
    cout<<"Absent"<<endl;
    cout<<m[index].name<<" "<<m[index].id<<endl;
    cout<<"NA";
  }
  else if(lM==0)
  {
	int index=0;
	for(int i=1;i<lF;i++)
	{
		if(f[i].score>f[index].score)
			index=i;
	}
    cout<<"Absent"<<endl;
    cout<<f[index].name<<" "<<f[index].id<<endl;
    cout<<"NA";
  }
  else
  {
	int index1=0;
	for(int i=1;i<lF;i++)
	{
		if(f[i].score>f[index1].score)
			index1=i;
	}
    cout<<f[index1].name<<" "<<f[index1].id<<endl;
    	int index2=0;
	for(int i=1;i<lM;i++)
	{
		if(m[i].score<m[index2].score)
			index2=i;
	}

    cout<<m[index2].name<<" "<<m[index2].id<<endl;
    cout<<f[index1].score-m[index2].score;
  }
  return 0;
}
