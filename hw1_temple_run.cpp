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

vector<string> miss(vector<string> &a)
{
    if(!a.empty())
    {
        int idx=0;
        for(int i=0;i<a.size();i++)
        {
            idx=i;
            if(i-4>=0)
            {
                idx-=4;
            }
            else
            {
                idx=0;
            }
            if(a[i]=="MISS")
            {
                for(int j=i;j>=idx;j--)
                {
                    a[j]="";    
                }
            }
            
        }
        
    }
    return a;
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
    // for(auto &a:treasure)
    // {
    //     cout<<a<<endl;
    // }
    // cout<<endl;
    
    value_no_miss=get_value(treasure);
    treasure=miss(treasure);
    value_with_miss=get_value(treasure); 
    
    // for(auto &a:treasure)
    // {
    //     cout<<a<<endl;
    // }

   
    
    cout<<trace<<endl;
    cout<<value_with_miss<<endl;
    cout<<value_no_miss<<endl;
    
    return 0;
}
