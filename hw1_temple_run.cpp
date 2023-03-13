#include<iostream>

#include<string>
using namespace std;

const int MaxSize=101;



template <class T>
class stack
{
    private:
        T stack[MaxSize];
        int top=0;
       
    
    public:
        bool empty()
        {
            if(top<0)
            {
                return true;
            }
            else{
                return false;
            }
        }

        T pop()
        {
            T item;
            if(this->empty())
            {
                cout<<"stack is empty"<<endl;
                exit(-1);
            }
            item= stack[top];
            top--;
            return item;
        }

        void push(T item)
        {
            if(top>=MaxSize-1)
            {
                cout<<"stack is full"<<endl;
                exit(-1);
            }
            top++;
            stack[top]=item;
        }

        int size()
        {
            return top;
        }

    

        void show()
        {
            for(int i=1;i<=this->size();i++)
            {
                cout<<stack[i]<<endl;
            }
        }

};

template <class T>
class queue
{
    private:
        T queue[MaxSize];
        int front=0;
        int back=0;
        int size=0;
        
    
    public:
        int get_size()
        {
            return size;
        }
        void push_back(T item)
        {
            if(this->size >= MaxSize-1)
            {
                cout<<"queue is full"<<endl;
                exit(-1);
            }
            back=(back+1)%MaxSize;
            queue[back]=item;
            size++;
        }

        T pop_front()
        {
            T item;
            if(this->empty())
            {
                cout<<"queue is empty"<<endl;
                exit(-1);
            }
            front=(front+1)%MaxSize;
            item = queue[front];
            size--;
            return item;
        }

        bool empty()
        {
            if(this->size<=0)
            {
                return true;
            }
            return false;
        }

        void show()
        {
            for(int i=front+1;i<=back;i=(i+1)%MaxSize)
            {
                cout<<queue[i]<<endl;
            }
        }

};



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
