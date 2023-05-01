#include"tree.h"

int main()
{
    string in;
    tree<int> l_tree;
    tree<int> r_tree;
    int total=0;
    int re=0;
    while(getline(cin,in))
    {
        if(in=="Spade")
        {
            break;
        }
        else if(in=="Clubs")
        {
            node<int> *nd=new node<int>(1,0,0); 
            if(l_tree.r_root()==NULL)
            {
                l_tree.change_root(nd);
                
            }
            else if(r_tree.r_root()==NULL)
            {
                r_tree.change_root(nd);
                
            }

        }
        else if(in=="Diamond" && (l_tree.r_root()!=NULL || r_tree.r_root()!=NULL))
        {
            node<int> *nd=new node<int>(3,0,0);
            tree<int> temp;
            if((l_tree.r_root()!=NULL && r_tree.r_root()==NULL) ||(r_tree.r_root()!=NULL && (l_tree.r_root()->val()<=r_tree.r_root()->val()) ))
            {
                temp.change_root(nd);
                temp.add_left(l_tree.r_root());
                l_tree.change_root(temp.r_root());
                
            }
            else if((l_tree.r_root()!=NULL && r_tree.r_root()!=NULL) )
            {
                temp.change_root(nd);
                temp.add_right(r_tree.r_root());
                r_tree.change_root(temp.r_root());
               
            }
        }
        else if(in=="Heart" && (l_tree.r_root()!=NULL && r_tree.r_root()!=NULL))
        {
            
            node<int> *nd=new node<int> (3,0,0);
            tree<int> temp;
            temp.change_root(nd);
            temp.add_left(l_tree.r_root());
            temp.add_right(r_tree.r_root());
            temp.preorder(temp.r_root()->left,&total);
            
            re+=total;
            total=0;
            temp.preorder(temp.r_root()->right,&total);
            
            re-=total;
            total=0;
            l_tree.change_root(temp.r_root());
            r_tree.change_root(NULL);
        }
        
    }
    cout<<re<<endl;
    return 0;
}