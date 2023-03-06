#include<string>
#include<iostream>
using namespace std;

int main()
{
	string target,result;
	getline(cin, target);
	
	int p=target.length();
	while(p>0)
	{
		p--;
		result+=target[p];
	}
	cout<<result<<endl;
	return 0;
}
