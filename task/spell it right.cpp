#include<iostream>
#include<string>

using namespace std;
void output(int index)
{
	switch(index)
	{
		case 1:cout<<"one";break;
		case 2:cout<<"two";break;
		case 3:cout<<"thress";break;
		case 4:cout<<"four";break;
		case 5:cout<<"five";break;
		case 6:cout<<"six";break;
		case 7:cout<<"seven";break;
		case 8:cout<<"eight";break;
		case 9:cout<<"nine";break;
		case 0:cout<<"zero";break;
	}
}
int main()
{
	string input;
	cin>>input;
	int sum=0;
	for(int i=0;i<input.length();i++)
	{
		sum+=input[i]-'0';
	}

	string r=to_string(sum);
	output(r[0]-'0');
	for(int i=1;i<r.length();i++)
	{
		cout<<" ";
		output(r[i]-'0');
	}
	return 0;
}
