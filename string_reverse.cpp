#include<string>
#include<iostream>
using namespace std;

int main()
{
	string target,result;
	getline(cin, target);
	auto p=target.end();
	while(p!=target.begin())
	{
		p--;
		result+= *p;
			
	}
	cout<<result<<endl;
	return 0;
}
