#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

int main()
{
    queue<string> data;
    stack<string> route;
    stack<int> time;
    queue<string> toast;
    stack<int> cups;
    string item;

    string toast_result;
    int cups_result=0;
    string route_result;
    int time_result=0;



    while(getline(cin,item))
    {
        if (item=="")
        break;
        data.push(item);
    }

    while(!data.empty())
    {
        item=data.front();
        data.pop();
        if(item=="R")
        {
            item=data.front();
            data.pop();
            route.push(item.substr(0, item.find(" ")));
            time.push(stoi(item.substr(item.find(" ") + 1, item.length())));
        }
        if(item=="T")
        {
            item=data.front();
            data.pop();
            toast.push(item.substr(0, item.find(" ")));
            cups.push(stoi(item.substr(item.find(" ") + 1, item.length())));
        }
        
    }


    while(!route.empty())
    {
        route_result += route.top();
        route_result +=' ';
        route.pop();
    }
    while(!toast.empty())
    {
        toast_result+= toast.front();
        toast_result +=' ';
        toast.pop();
    }
    while(!cups.empty())
    {
        
        cups_result += cups.top();
        cups.pop();
    }
    
    int last_time;
    int first_time=time.top();
    while(!time.empty())
    {
        last_time=time.top();
        time.pop();
    }

    time_result=first_time-last_time;

    cout<<route_result<<endl;
    cout<<time_result<<endl;
    cout<<toast_result<<endl;
    cout<<cups_result<<endl;

    return 0;
}