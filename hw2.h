#ifndef HW2_H
#define HW2_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class node{
    public:
        node<T>():item(0),label(0),next(NULL){};
        node<T>(T a,int b):item(a),label(b),next(NULL){};
        int label;
        T item;
        node<T> *next; 
};

template <class T>
class linklist{
    private:
        node<T>* head;
    public:
        linklist<T>():head(NULL){};
        linklist<T>(linklist *a):head(a.head){};
        void insert(node<T> *new_node)
        {
            if(this->head==NULL)
            {
                this->head=new_node;
            }
            else
            {
                new_node->next=this->head;
                this->head=new_node;
            }
        }
        T pop()
        {
            T result;
            result=this->head->item;
            this->head=this->head->next;
            return result;
        }
        bool empty()
        {
            return (this->head==NULL)?true:false;
        }

        node<T>* truncate(int a, int b) //from a to the next b items
        {
            node<T> *p=head, *r=head, *part_h=head, *part_e=head;
            for(int i=0;i<a-1;i++)
            {
                p=p->next;
            }
            part_h=p->next;
            for(int i=0;i<a+b-1;i++)
            {
                part_e=part_e->next;
            }
            r=part_e->next;

            p->next=r;
            part_e->next=NULL;
            return part_h;
        }

        void glue(int a, node<T> *temp) //add after a
        {   
            node<T> *p=head, *q=head ,*r=temp;
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                for(int i=0;i<a;i++)
                {
                    p=p->next;
                }
                if(p->next==NULL)
                {
                    p->next=r;
                }
                else
                {
                    q=p->next;
                    p->next=r;
                    while(r->next!=NULL)
                    {
                        r=r->next;
                    }
                    r->next=q;
                }
                
            }

        }

        void show()
        {
            node<T> *p=head;
            while(p!=NULL)
            {
                cout<<p->label<<" / "<<p->item<<endl;
                p=p->next;
            }
        }

        void inverse()
        {
            node<T> *p=head, *q=NULL, *r=NULL;
            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            head=q;
        }
        node<T>* return_head()
        {
            return head;
        }

        void reset(int a)
        {
            node<T> *p=head,*q=head,*temp=head;
            int index=0;
            if(a!=0)
            {
                for(int i=0;i<a-1;i++)
                {
                    p=p->next;
                }
                q=p->next;
                this->head=q;
                p->next=NULL;
                while(q!=NULL)
                {
                    q=q->next;
                    index++;
                }
                
                this->glue(index-1,temp);
            } 
        }

        int find_target()
        {
            T cur=this->head->item;
            node<T> *tar=head;
            T tar_item=0;
            int tar_idx=10;
            int index=0;
            int tar_id=-1;

            for(int i=0;i<6;i++)
            {
                tar=tar->next;
                if(i>2)
                {
                    index=6-i;
                }
                else
                {
                    index++;
                }

                if(tar->item<cur && tar->item>tar_item)
                {
                    tar_item=tar->item;
                    tar_idx=index;
                    tar_id=i;
                }
                else if(tar->item<cur && tar->item==tar_item && tar_idx>index)
                {
                    tar_item=tar->item;
                    tar_idx=index;
                    tar_id=i;
                }
            }
            if(tar_id==-1)
            {
                tar=head;
                tar_item=0;
                for(int i=0;i<6;i++)
                {
                    tar=tar->next;
                    if(tar->item>tar_item)
                    {
                        tar_item=tar->item;
                        tar_id=i;
                    }
                }
            }
            if(tar_id==-1)
            {
                tar_id=0;
            }
            
            return tar_id+1;
        }

        int find_cur(int cur)
        {
            node<T> *p=head;
            int count=0;
            while(p!=NULL)
            {
                p=p->next;
                count++;
                if(p->label==cur)
                {
                    return count;
                }
                
            }
            return count;
        }
};

#endif