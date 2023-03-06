#include<iostream>
using namespace std;

bool getvalue(int cur_val, int val, int item_val)
{
	if(cur_val+item_val<=val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int main()
{
	int *target= new int[2];


	string a;
	getline(cin, a);
	target[0] = stoi(a.substr(0, a.find(" ")));
	target[1] = stoi(a.substr(a.find(" ") + 1, a.length()));
	
	int item[target[0]][2];
	
	for(int i=0;i<target[0];i++)
	{
		getline(cin,a);
		item[i][0]=stoi(a.substr(0, a.find(" ")));
		item[i][1]=stoi(a.substr(a.find(" ") + 1, a.length()));
	}

	int cur_val=0;
	int weight=0;
	for(int i=0; i<target[0];i++)
	{
		if(getvalue(cur_val,target[1],item[i][0]))
		{
			cur_val+=item[i][0];
			weight+=item[i][1];
		}
	}

	cout<<weight;

	return 0;
}
