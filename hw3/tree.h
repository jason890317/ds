#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>
using namespace std;
template <class T>
class node
{
    
    public:
        T item;
        node<T> *right;
        node<T> *left;
        node<T>():item(0),right(NULL),left(NULL){};
        node<T>(T it, node<T> *r, node<T> *l):item(it),right(r),left(l){};
        T val()  
        {
            return item;
        }
        void val(T it)
        {
            item=it;
        }
};

template <class T>
class tree : public node<T>
{
    private:
        node<T> *root;
    public:
        tree():root(NULL){};
        tree(node<T> *it):root(it){};
        void add_right(node<T> *it)
        {
            root->right=it;
        }

        void add_left(node<T> *it)
        {
            root->left=it;
        }

        void change_root(node<T> *it)
        {
            root=it;
        }
        node<T>* r_root()
        {
            return root;
        }
        string preorder(node<T> *cur)
        {
            static string result="";
            if(cur!=NULL)
            {
                if(cur->val()!=0)
                {
                    result+=to_string((int)cur->val());
                    result+=" ";
                }
                
                preorder(cur->left);
                preorder(cur->right);
            }
            return result;
        }
        
};


#endif