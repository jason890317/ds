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
                    result+="* ";
                }
                
                preorder(cur->left);
                preorder(cur->right);
            }
            return result;
        }
        
};


int main()
{
    tree<double> l_tree;
    tree<double> r_tree;
    double total_damage=0;
    double new_star=0;
    string in;
    while(getline(cin,in))
    {
        if (in=="TheEnd")
        {
            break;
        }
        else if(in == "Attack")
        {   
            if(l_tree.r_root()!=NULL)
            {
                total_damage+=l_tree.r_root()->val();
            }
            if(r_tree.r_root()!=NULL)
            {
                total_damage+=r_tree.r_root()->val();
            }
        }
        else
        {
            new_star=in[10]-'0';
            node<double> *monster =new node<double>;
            monster->val(new_star);

            if(new_star<=4)
            {
                if(l_tree.r_root()==NULL)
                {
                    l_tree.change_root(monster);
                }
                else if(r_tree.r_root()==NULL)
                {
                    r_tree.change_root(monster);
                }
            }
            else if(new_star<=6 && new_star >=5)
            {
                tree<double> temp;
                temp.change_root(monster);

                if((l_tree.r_root()!=NULL && r_tree.r_root()==NULL) ||(r_tree.r_root()!=NULL && l_tree.r_root()->val()<=r_tree.r_root()->val()) )
                {
                    temp.add_left(l_tree.r_root());
                    l_tree.change_root(temp.r_root());
                }
                else if((l_tree.r_root()!=NULL && r_tree.r_root()!=NULL) )
                {
                    temp.add_left(r_tree.r_root());
                    r_tree.change_root(temp.r_root());
                }
                else
                {
                    cout<<"fail"<<endl;
                }
            }
            else if(new_star<=8 && new_star >=7)
            {
                tree<double> temp;
                temp.change_root(monster);
                if(l_tree.r_root()!=NULL && r_tree.r_root()!=NULL)
                {
                    temp.add_left(l_tree.r_root());
                    temp.add_right(r_tree.r_root());
                    l_tree.change_root(temp.r_root());
                    r_tree.change_root(NULL);
                }
            }
        }
        
    }
    tree<double> temp;
    node<double> n;
    string result;
    temp.change_root(&n);
    temp.add_left(l_tree.r_root());
    temp.add_right(r_tree.r_root());
    result=temp.preorder(temp.r_root());
    if(result!="")
    {
        result.pop_back();
    }
    cout<<result<<endl;
    cout<<total_damage<<endl;
    return 0;
}