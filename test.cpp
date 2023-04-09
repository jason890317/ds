#include"string_tool.h"
#include"list.h"
int main()
{
	string a;
	string *c;
	linklist<string> l;
	string_tool b;
	int num=0;
	while(getline(cin,a))
	{	
		if(a=="")
		{	
			break;
		}
		b.put(a);
		c=b.split(' ');
		for(int i=0;i<b.slt_num();i++)
		{
			l.insert(b.split()[i]);
		}
	}
	l.show();
	return 0;
}
