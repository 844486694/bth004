#include<instream>
#include<string>
#include<vector>


struct book
{
	string detail[5];
	int id;
};

vector<book> books;
int n,m;
int main()
{
	
	scanf("%d",&n);
	books.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%s%s%s%s%s",&book[i].id,&book[i].detail[0],&book[i].detail[1],&book[i].detail[2],&book[i].detail[3],&book[i].detail[4]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		string info; 
		scanf("%d:%s",&x,&info);
		bool found=false;
		for(int j=0;j<n;j++)
		{
			if(x-1==2)
			{
				if(books[j].detail[x-1].find(info)!=-1)
				{
					found=true;
					cout<<book[j].id<<id;
				}
			}
			else
			{
				if(book[j].detail[x-1].cmp(info))
			}
		}
		
	}
	
	
	return 0l
}
