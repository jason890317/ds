#include<iostream>
#include<vector>
#include<string>
using namespace std;

int get_value(vector<string> a)
{
    int count=0;
    int gold_count=0;
    int value=0;
    string item;
    while(!a.empty())
    {
        //get item in vector
        item=a.back();
        a.pop_back();
        
        //skip "MISS"
        if(item=="MISS")
        {
            continue;
        }

        //record the count
        count++;

        //count the "GOLD" number in every three itms 
        if(item=="GOLD")
        {
            gold_count++;
        }

        //check the value every three items
        if(count==3)
        {
            if(gold_count==3)
            {
                value+=500;
            }
            else if (gold_count==2)
            {
                value+=300;
            }
            else if(gold_count==1)
            {
                value+=150;
            }
            else{
                value+=50;
            }
            count=0;
            gold_count=0;
        }
    }
    return value;
}

void miss(vector<string> &a)
{
    for(auto x=a.end()-1;x!=a.begin();x--)
    {
        if(*x=="MISS")
        {
            a.erase(x-4,x+1);
        }
    }
}

int main()
{
    vector<string> record;
    string event,trace;
    int value_no_miss, value_with_miss;

    vector<string> treasure;
    while(getline(cin,event))
    {
        if (event=="")
        break;
        record.push_back(event);
    }
    
    while(!record.empty())
    {
        event=record.back();
        record.pop_back();
        if(event=="TL")
        {
            trace+="TR->";
        }
        if(event=="TR")
        {
            trace+="TL->";
        }
        if(event=="GOLD" | event=="SILVER" | event=="MISS")
        {
            treasure.push_back(event);
        }
    }
    trace.erase(trace.length()-2,trace.length());
    
    
    value_no_miss=get_value(treasure);
    miss(treasure);
    value_with_miss=get_value(treasure); 
    
    cout<<trace<<endl;
    cout<<value_with_miss<<endl;
    cout<<value_no_miss<<endl;
    
    return 0;
}
