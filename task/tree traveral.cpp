#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,t;
struct node
{
	int index,value;
};
vector<int> post,inorder;
vector<node> tree;

void  convert(int root,int start,int end,int index)
{
	if(start=end)return;
	int i=start;
	while(index<end&&inorder[i]!=post[root])i++;
	tree.push_back({index,post[root]});
	convert(root-(end-i+1),start,i-1,2*index+1);
	convert(root-1,i+1,end,2*index+2);

}
bool cmp(node a, node b)
{
	return a.index<b.index;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		post.push_back(t);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		inorder.push_back(t);
	}
	
	convert(n-1,0,n-1,0);
	sort(tree.begin(),tree.end(),cmp);
	for(int i=0;i<tree.size();i++)
	{
		printf("%d",tree[i].value);
		if(i!=tree.size()-1)
			printf(" ");
	}
	
	
	
	
	return 0;
}

