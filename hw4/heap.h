#ifndef HEAP_H
#define HEAP_H

#include"list.h"

template <class T>
class heap
{
    public:
        list<T> main_heap;
        heap():main_heap(){};

        void add(T a)
        {
            main_heap.add_node(a);
            this->heap_sort();
        }

        void construct(int a)// a=> 1~n
        {
            int si=main_heap.size();
            
            if(2*a+1 <= si && main_heap.node_no(a-1)->item < main_heap.node_no(2*a+1-1)->item)
            {
                main_heap.swap(a-1,2*a+1-1);
            }
            if(2*a <= si && main_heap.node_no(a-1)->item < main_heap.node_no(2*a-1)->item)
            {
                main_heap.swap(a-1,2*a-1);
            }
            
        }
        
        node<T>* del_max()
        {
            node<T> *cur=main_heap.cut(0,1);
            node<T> *p=main_heap.cut(main_heap.size()-1,1);
            main_heap.paste(-1,p);
            
            int c=main_heap.size()/2;
            for(int i=1;i<=c;i++)
            {
                this->construct(i);
            }
            
            return cur;
        }

        void heap_sort()
        {
            int cur=main_heap.size()/2;
            for(int i=cur;i>0;i--)
            {
                this->construct(i);
            }
        }
        void show()
        {
            main_heap.show();
        }
};


#endif