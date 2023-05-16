#include<cmath>
#include<vector>
#include<queue>
using namespace std;


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

};
class n_edge
{
    public:
        int to[2];
        float distance;
        int mes;
        n_edge(int a,int b,float c,int m)
        {
            to[0]=a;
            to[1]=b;
            distance=c;
            mes=m;
        }
};


int* find_path(int **pre,int to, int from, int n)
{
    int **temp = new int*[n];
    int *result=new int[n];
    int min=999999;
    int *check=new int[n];
    for(int i=0;i<n;i++)
    {
        temp[i]=new int[n];
        check[i]=0;
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            temp[i][j]=-1;
        }
    }
    int t=0;
    queue<int> pu;
    int tar;
    pu.push(to);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<pre[i][j]<<endl;
    //     }
    //     cout<<endl; 
    // }  
    while(!pu.empty())
    {
        tar=pu.front();
        pu.pop();
        min=999999;
        for(int i=0;i<n;i++)
        {
            if(pre[tar][i]!=-10000000 && pre[tar][i]<min)
            {
                min=pre[tar][i];
            }
        }
        // cout<<"target :"<<tar<<"min : "<<min<<endl;
        for(int i=0;i<n;i++)
        {
            
            if(pre[tar][i]==min)
            {
                t=0;
                while(temp[i][t]!=-1)
                {
                    t++;
                }
                temp[i][t]=tar;
                pu.push(i);
                // cout<<i<<endl;
            }
        }
    }
     
    for(int i=0;i<n;i++)
    {
        min=999;
        for(int j=0;j<n;j++)
        {
            if(temp[i][j]!=-1 && temp[i][j]<min)
            {
                min=temp[i][j];
            }
        }
        result[i]=min;
    }

    return result;
}

void Dijkstra(vector<n_edge> edge,vector<pair<string,string>> node,float *graph[])
{   
    int n=node.size();
    int **pre = new int*[n];
    float d[n];
    int visit[n];
    int from;
    int to;
    int mess=0;
    float short_dis;
    int test=n;
    string result="";
    vector<string> re;
    vector<int> que;
    for(int i=0;i<n;i++)
    {
        pre[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pre[i][j]=-10000000;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(node[i].first=="SOURCE")
        {
            from=i;
           
        }
        if(node[i].first=="HQ")
        {
            to=i;
            
        }
        d[i]=1000000;
        visit[i]=0;
    }
    d[from]=0;
    
    for (int i = 0; i < n; ++i)
    {
        int u = -1;                                     
        int MIN = 1000000;                                  
        for (int j = 0; j < n; ++j)                     
        {
            if (visit[j] == 0 && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        
        if (u == -1)
                return;
        visit[u] = 1;        
        // cout<<u<<endl;                            
        for (int v = 0; v <n; v++)
        {
            if(node[u].first=="SOURCE" && node[v].first=="SPY")
            {
                continue;
            }
            if(node[u].first=="SPY" && node[v].first=="SPY")
            {
                continue;
            }
            if(node[u].first=="CIV" && node[v].first=="HQ")
            {
                continue;
            }
            if (visit[v] == 0 && d[u] + graph[u][v] <= d[v]) {
                d[v] = d[u] + graph[u][v];            
                pre[v][u] = d[v];
                                        
            }
        }
    }
    short_dis=d[to];
    
    
    int *final_path=new int[n];
    
    final_path=find_path(pre,to,from,n);
    int t=from;
    while(t!=999)
    {
        result+=node[t].second;
        result+=" -> ";
        
        for(int i=0;i<edge.size();i++)
        {
            if((edge[i].to[1]==t+1 && edge[i].to[0]==final_path[t]+1) || (edge[i].to[0]==t+1 && edge[i].to[1]==final_path[t]+1))
            {
                mess+=edge[i].mes;
            }
        }
        t=final_path[t];

    }
    
    result.pop_back();
    result.pop_back();
    result.pop_back();
    result.pop_back();
     
    
    cout<<result<<endl;
    cout<<mess<<endl;
    cout<<short_dis<<endl;
};

int main()
{
    int node_num=0;
    int edge_num=0;
    string in;
    string_tool tool;
    string *tar;
    
    float dis=0;
     
   
    vector<n_edge> edge;
    vector<pair<string,string>> node;
    
   
    
    while(getline(cin,in))
    {
        if(in=="")
        {
            break;
        }
        if(in[0]=='I' && in[6]==' ')
        {
            node_num++;
            tool.put(in);
            tar=tool.split(' ');
            node.emplace_back(tar[1], tar[2]);
        }
        else if(in[6]=='_')
        {   
            edge_num++;
            tool.put(in);
            tar=tool.split(' ');
            if(tar[3]!="0")
            {
                dis=round(1000/stof(tar[3])*100)/100;
                edge.emplace_back(stoi(tar[1]), stoi(tar[2]), dis,stoi(tar[3]));
            }
        }
        else if(in[6]=='E')
        {
            break;
        }
    }
    float **graph=new float*[node_num];
    for(int j=0;j<node_num;j++)
    {
        graph[j]=new float[node_num];
    }
    for(int i=0;i<node_num;i++)
    {
        for(int j=0;j<node_num;j++)
        {
            graph[i][j]=1000000;
        }
    }
    for(auto i: edge)
    {
        graph[i.to[0]-1][i.to[1]-1]=i.distance;
        graph[i.to[1]-1][i.to[0]-1]=i.distance;
    }
    
    Dijkstra(edge,node,graph);
    
   
    return 0;
}