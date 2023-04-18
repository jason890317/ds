#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;
template <class T>
class node
{
    protected:
        T item;
        node<T> *right;
        node<T> *left;
    public:
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
};


#endif