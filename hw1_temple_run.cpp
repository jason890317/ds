#include<iostream>
#include"queue.h"
#include<string>
#include"stack.h"

using namespace std;

int treasure_value(stack<string> tr)
{
    int cnt=0;
    int gold=0;
    int tr_val=0;
    string item;
    while(!tr.empty()){
        item=tr.pop();
        if(item=="MISS" | item==""){
            continue;
        }
        cnt++;
        if(item=="GOLD"){
            gold++;
        }
        if(cnt==3){
            if(gold==3){
                tr_val+=500;
            }
            else if(gold==2){
                tr_val+=300;
            }
            else if(gold==1){
                tr_val+=150;
            }
            else{
                tr_val+=50;
            }
            cnt=0;
            gold=0;
        }
    }
    return tr_val;
}

int count_miss(stack<string> miss_stack)
{
    int not_count=5;
    string treasure;
    stack<string> b;
    while(!miss_stack.empty()){
        treasure=miss_stack.pop();
        if(treasure=="MISS"){
            not_count=0;
        }
        if(not_count<5){
            treasure="";
            not_count++;
        }
        b.push(treasure);
    }
    b.reverse();
    return treasure_value(b);
}

int main()
{
    stack<string> data;
    stack<string> tr_item; 
    string item,path;
    while(getline(cin,item))
    {
        if (item=="")
        break;
        data.push(item);
    }
    while(!data.empty())
    {
        item=data.pop();
        
        if(item=="TL")
        {
            path+="TR->";
        }
        if(item=="TR")
        {
            path+="TL->";
        }
        if(item=="GOLD" | item=="SILVER" | item=="MISS")
        {
            tr_item.push(item);
        }
    }
    path.erase(path.length()-2,path.length());
    cout<<path<<endl;
    cout<<count_miss(tr_item)<<endl;
    cout<<treasure_value(tr_item)<<endl;
    return 0;
}
