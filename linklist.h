#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
using namespace std;

template<class T>
class LinkList;

template<class T>
class node
{
    private:
        T value;
        node* nextNode;
    
    public:
        node():nextNode(NULL){};
        node(T a):value(a),nextNode(NULL){};
    
    friend class LinkList<T>;
};

template<class T>
class LinkList
{
    private:
        node<T>* head;
        int size;
    public:
        LinkList<T>():head(NULL),size(0){};
        
        void reverse()
        {
            node<T>*p=head;
            node<T>*q=NULL;
            node<T>*r=NULL;

            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->nextNode;
                q->nextNode=r;
            }
            head=q;
        }

        void print()
        {
            node<T>* p=head;
            while(p!=NULL)
            {
                cout<<p->value<<endl;
                p=p->nextNode;
            }
        }

        void insert(T item)
        {
            node<T>* NewNode = new node<T>(item);
            if(head==NULL)
            {
                head=NewNode;
            }
            else
            {
                NewNode->nextNode=head;
                head=NewNode;
            }
        }
        
        T pop()
        {
            T item=head->value;
            head=head->nextNode;
            return item;
        }

        void delet(T item)
        {
            node<T> *p=head;
            node<T> *q=p;
            while(p->value==item)
            {
                p=p->nextNode;
                head=p;
            }
            while(p->nextNode!=NULL)
            {
                q=p->nextNode;
                while(q->value==item)
                {
                    if(q->nextNode!=NULL)
                    {
                        q=q->nextNode;
                    }
                    else
                    {
                        break;
                    }
                }
                if(q->value==item)
                {
                    p->nextNode=NULL;
                }
                else{
                    p->nextNode=q;
                }
                p=q;
            }
        }

        int len()
        {
            node<T>* p=head;
            size=0;
            while(p!=NULL)
            {
                size++;
                p=p->nextNode;
            }
            return size;
        }
};

#endif 