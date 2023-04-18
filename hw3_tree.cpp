#include"tree.h"
#include"string_tool.h"
#include<string>
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
            string_tool input(in);
            input.elimate(' ');
            new_star=input.show_string()[8]-'0';
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
            }
        }
        
    }
    return 0;
}