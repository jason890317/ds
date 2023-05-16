#ifndef STRING_TOOL_H
#define STRING_TOLL_H

#include<iostream>
#include<string.h>

using namespace std;

class string_tool
{
    private:
        string target;
        string *split_result;
        int split_num=0;
    public:
        string_tool(string a):target(a),split_result(0){};
        string_tool():target(""),split_result(0){};
        
        void put(string a)
        {
            target=a;
        }
        
        string show_string()
        {
            return target;
        }

        void reverse()
        {
            string result;
            auto p=target.end();
            while(p!=target.begin())
            {
                p--;
                result+= *p;
            }
            target=result;
        }

        void elimate(char item)
        {
            string result="";
            int num=0;
            auto a=target.begin();
            
            while(a!=target.end())
            {
                if(*a!=item)
                {
                    result+=*a;
                }
                a++;
            }
            target=result;
        }

        string* split(char cut)
        {
            delete [] split_result;
            split_num=0;
            int num=0;
            string temp=target+=cut;
            int stop=1;
            auto a=temp.begin();
            while(a!=temp.end())
            {
                if(*a==cut && stop==0)
                {
                    stop=1;
                    num++;
                }
                else if(*a != cut)
                {
                    stop=0;
                }
                a++;
            }
            string *result=new string[num];
            split_num=num;

            a=temp.begin();
            stop=1;
            num=0;
            while(a!=temp.end())
            {
                if(*a==cut && stop==0)
                {
                    stop=1;
                    num++;
                }
                else if(*a != cut )
                {
                    stop=0;
                    result[num]+=*a;
                }
                
                a++;
            }
            split_result=result;
            return split_result;
        }

        string* split()
        {
            return split_result;
        }
        
        int slt_num()
        {
            return split_num;
        }
};

#endif
