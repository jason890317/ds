#include "hw2.h"

int main()
{
    string in;
    linklist<int> list;
    linklist<int> inv;
    node<int> *tar;
    node<int> *temp;
    int tar_id,cur;
    int index=0;
    node<int> *plates=new node<int>[10];
    while(getline(cin,in))
    {
        if (in=="")
        break;
        plates[index].item=stoi(in);
        plates[index].label=index+1;
        list.insert(&plates[index]);
        index++;
    }

    list.inverse();
    
    for(int i=0;i<10;i++)
    {
        temp=list.truncate(1,3);
        inv.glue(0,temp);
        inv.inverse();
        tar_id=list.find_target();
        list.reset(tar_id);
        tar=list.return_head();
        if(tar->item < tar->label)
        {
            tar->item+=50;
        }
        tar->item-=tar->label;
       
        list.glue(0,inv.return_head());
        while(!inv.empty())
        {
            inv.pop();
        }
        cur=(list.return_head()->label%10)+1;
        list.reset(list.find_cur(cur));
        
        
        list.show();
        cout<<endl;
    }
    // list.reset(list.find_cur(tar->label));
    // list.show();
    return 0;
}