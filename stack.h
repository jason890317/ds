#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

const int Max_Size=101;
template <class T>
class stack
{
    private:
        
        T stack[Max_Size];
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
            if(top>=Max_Size-1)
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

#endif
