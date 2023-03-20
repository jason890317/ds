#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MaxSize=101;
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

#endif
