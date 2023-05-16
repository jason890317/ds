#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<string>
using namespace std;

class node
{
    public:
        node():item(""),type(""),next(NULL){};
        node(string it, string a)
        {
            item=it;
            type=a;
            
        }
        string item;
        string type;
        float **edge;
        node *next;
        int table;
    public:
        void create(int b)
        {
            edge= new float*[b];
            for(int i=0;i<b;i++)
            {
                edge[i]=new float[3];
                edge[i][0]=i+1;
                edge[i][1]=1000000;
                edge[i][2]=1;
            }
            table=b;
        }
        void add_edge(int d, float l)
        {
            edge[d-1][1]=l;
            edge[d-1][2]=0;

        }

        void show_edge()
        {
            for(int i=0;i<table;i++)
            {
                cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;
            }
            cout<<endl;
        }
   
};


class list : public node
{
    public:
        node *root;
        list()
        {
            node *b=new node("dummy","dummy");
            root=b;
        }
        void add_node(string it,string a)
        {
            node *n=new node(it,a);
            node *cur=root;
            if(cur==NULL)
            {
                root=n;
            }
            else
            {
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                cur->next=n;
            }
            
        }
        void show()
        {
            node *cur=root;
            while(cur!=NULL)
            {
                cout<<cur->item<<" ";
                cur=cur->next;
            }
        }

        void create(int b)
        {
            node *cur=root;
            while(cur!=NULL)
            {
                cur->create(b);
                cur=cur->next;
            }
        }
        int size()
        {
            int num=0;
            for(node *cur=root;cur!=NULL;cur=cur->next)
            {
                num++;
            }
            return num;
        }

        void show_graph()
        {
            node *cur=root;
            while(cur!=NULL)
            {
                cur->show_edge();
                cur=cur->next;
            }
        }

        node* node_no(int a)
        {
            node *cur=root;
            if(a<this->size())
            {
                for(int i=0;i<a;i++)
                {
                    cur=cur->next;
                }
            }
            
            return cur;
        }


};


#endif