#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class node{
    public:
        node<T>():item(0),num(0),next(NULL){};
        node<T>(T a):item(a),num(0){};
        node<T>(T a,int b):item(a),num(b),next(NULL){};
        int num;
        T item;
        node<T> *next; 
};

template <class T>
class linklist{
    private:
        node<T>* head;
        int size;
    public:
        linklist<T>():head(NULL),size(0){};
        linklist<T>(linklist *a):head(a->head),size(a->size){};
        void insert(T item , int num=0)
        {
            node<T> *new_node= new node<T>(item, num);
            if(this->head==NULL)
            {
                this->head=new_node;
            }
            else
            {
                new_node->next=this->head;
                this->head=new_node;
            }
            size++;
        }
        T pop()
        {
            T result;
            result=this->head->item;
            this->head=this->head->next;
            size--;
            return result;
        }
        bool empty()
        {
            return (this->head==NULL)?true:false;
        }

        void size_count()
        {
            int c=0;
            node<T> *p=head;
            while(p!=NULL)
            {
                c++;
                p=p->next;
            }
            size=c;
        }

        //0~n-1
        linklist<T>* extract(int a, int b) //from a to the next b items (a!=0)
        {
            node<T> *p=head, *r=head, *part_h=head, *part_e=head;
            linklist<T> *new_list = new linklist<T>;
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
            while(part_h!=NULL)
            {
                new_list->insert(part_h->item);
                part_h=part_h->next;
            }
            new_list->inverse(); //make the order right
            size_count();
            return new_list;
        }

        //0~n-1
        void paste(int a, linklist<T> temp) //add after a
        {   
            node<T> *p=head, *q=head;
            linklist<T> *r=&temp;
            if(head==NULL)
            {
                head=r->head;
            }
            else
            {
                for(int i=0;i<a;i++)
                {
                    p=p->next;
                }
                if(p->next==NULL)
                {
                    p->next=r->head;
                }
                else
                {
                    q=p->next;
                    p->next=r->head;
                    while(r->head->next!=NULL)
                    {
                        r->head=r->head->next;
                    }
                    r->head->next=q;
                }   
            }
            size_count();
        }
        void show()
        {   
            node<T> *p=head;
            while(p!=NULL)
            {
                cout<<p->num<<" / "<<p->item<<endl;
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
       
        void swap(int a,int b)
        {
            node<T> *a_1=head,*a_2=head;
            int temp_num;
            T temp_item;
            for(int i=0;i<a;i++)
            {   
                a_1=a_1->next;
            }
            for(int i=0;i<b;i++)
            {   
                a_2=a_2->next;
            }
            temp_item=a_1->item;
            temp_num=a_1->num;

            a_1->item=a_2->item;
            a_1->num=a_2->num;

            a_2->item=temp_item;
            a_2->num=temp_num;

        }
        

        void sort(bool a)//big to small , 1 for item, 0 for num
        {
            node<T> *h=head;
            node<T> *p=h;
            int max;
            if(a)
            {
                max=head->item;
                for(int i=0;i<size-1;i++)
                {
                    p=h;
                    max=h->item;
                    
                    for(int j=i;j<size;j++)
                    {
                        if(p->item>max)
                        {
                            max=p->item;
                            swap(i,j);
                        }
                        p=p->next;
                    }
                                  
                    h=h->next;
                }
            }
            else
            {
                max=head->num;
                for(int i=0;i<size-1;i++)
                {
                    p=h;
                    max=h->num;
                    
                    for(int j=i;j<size;j++)
                    {
                        if(p->num>max)
                        {
                            max=p->num;
                            swap(i,j);
                        }
                        p=p->next;
                    }
                                  
                    h=h->next;
                }

            }
        }
        
        int find_max() //return 0~n-1
        {
            node<T> *p=head;
            int max=head->item;
            int count=0;
            int tar=0;
            while(p!=NULL)
            {
                if(p->item>max)
                {
                    max=p->item;
                    tar=count;
                }
                count++;
                p=p->next;
            }
            
            return tar;
        }

        node<T>* return_node(int a)
        {
            node<T> *p=head;
            for(int i=0;i<a;i++)
            {
                p=p->next;
            }
            return p;
        }

        //swap whole node (include address)
        // void swap(int a, int b)
        // {
        //     node<T> *a_1=head,*a_2=head,*a_3=head;
        //     node<T> *b_1=head,*b_2=head,*b_3=head;

        //     if(a!=0 && b-a>1)
        //     {
        //         for(int i=0;i<a-1;i++)
        //         {   
        //             a_1=a_1->next;
        //         }
        //         a_2=a_1->next;
        //         a_3=a_2->next;

        //         for(int i=0;i<b-1;i++)
        //         {
        //             b_1=b_1->next;
        //         }
        //         b_2=b_1->next;
        //         b_3=b_2->next;

        //         a_1->next=NULL;
        //         b_1->next=NULL;
        //         a_2->next=NULL;
        //         b_2->next=NULL;

        //         a_1->next=b_2;
        //         b_2->next=a_3;

        //         b_1->next=a_2;
        //         a_2->next=b_3;
        //     }
        //     else if(a!=0 && b-a==1)
        //     {
        //         for(int i=0;i<a-1;i++)
        //         {   
        //             a_1=a_1->next;
        //         }
        //         a_2=a_1->next;
        //         a_3=a_2->next;
                

        //         for(int i=0;i<b-1;i++)
        //         {
        //             b_1=b_1->next;
        //         }
        //         b_2=b_1->next;
        //         b_3=b_2->next;
                
        //         a_1->next=NULL;
        //         b_1->next=NULL;
        //         b_2->next=NULL;

        //         a_1->next=a_3;
        //         a_2->next=b_3;
        //         a_3->next=a_2;
        //     }
        //     else if(a==0)
        //     {
        //         linklist<T> fake;
        //         linklist<T> *temp;
        //         fake.insert(this->head->item,this->head->num);
        //         temp=this->extract(b,1);
        //         this->paste(b-1,fake);
        //         this->paste(0,*temp);
        //         this->pop();
        //     }
        // }
};

#endif