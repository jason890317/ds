#include<iostream>

#include<string>
#include"stack.h"

using namespace std;



int get_value(stack<string> a)
{
    int count=0;
    int gold_count=0;
    int value=0;
    string item;
    while(!a.empty())
    {
        //get item in vector
        item=a.pop();
        
        
        //skip "MISS"
        if(item=="MISS" | item=="")
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

int get_miss_value(stack<string> a)
{
    int count=5;
    string item;
    stack<string> b;
    while(!a.empty())
    {
        item=a.pop();
        if(item=="MISS")
        {
            count=0;
        }
        if(count<5)
        {
            item="";
            count++;
        }
        b.push(item);
    }
    while(!b.empty())
    {
        item=b.pop();
        a.push(item);
    }
    return get_value(a);
    
}

int main()
{
    stack<string> record;
    stack<string> treasure; 
    string event,trace;
    

    
    while(getline(cin,event))
    {
        if (event=="")
        break;
        record.push(event);
    }
    
    
    while(!record.empty())
    {
        event=record.pop();
        
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
            treasure.push(event);
        }
    }
    // treasure.show();
    trace.erase(trace.length()-2,trace.length());
    cout<<trace<<endl;
    cout<<get_miss_value(treasure)<<endl;
    cout<<get_value(treasure)<<endl;
    
    return 0;
}
