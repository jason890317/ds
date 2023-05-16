#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Fruit {
    std::string      name;
    std::vector<int> hyperFeatures;
};

struct GradBinHyperWeight {
    int                featureIdx;
    double             gradSlider;
    int                binThreshold;
    Fruit *R = nullptr;
    Fruit *L = nullptr;
    
    bool shouldBackward(Fruit& f) const
    {
        return f.hyperFeatures[featureIdx] < binThreshold;
    }
    void applyGradSlider(Fruit& f) const
    {
        f.hyperFeatures[featureIdx] = (int) ((double) f.hyperFeatures[featureIdx] * gradSlider);
        //cout<<f.hyperFeatures[featureIdx]<<endl;
    }
};

void sort(vector<Fruit> fruits,vector<GradBinHyperWeight> bins,int cur)
{
    vector<Fruit> left;
    vector<Fruit> right;
    if(fruits.size()==0)
    {
        return ;
    }
    if(fruits.size()==1)
    {   
        cout<<fruits[0].name<<" "<<fruits[0].hyperFeatures[bins[cur/2-1].featureIdx]<<endl;
        return; 
    }
    
    for(auto &i:fruits)
    {
        bins[cur-1].applyGradSlider(i);
    }
    for(auto &i:fruits)
    {
        if(bins[cur-1].shouldBackward(i))
        {
            left.push_back(i);
        }
        else
        {
            right.push_back(i);
        }
    }
    sort(left,bins,2*cur);
    sort(right, bins,2*cur+1);
}


int main()
{
    string in;
    int num_fruit=-1;
    int num_hype=-1;
    int num_bin=-1;


    vector<Fruit> fruits;
    vector<GradBinHyperWeight> bins;


    getline(cin,in);
    num_fruit=stoi(in);
    getline(cin,in);
    num_hype=stoi(in);
    for(int i=0;i<num_fruit;i++)
    {
        Fruit f;
        getline(cin,in);
        f.name=in;
        for(int j=0;j<num_hype;j++)
        {
            getline(cin,in);
            f.hyperFeatures.push_back(stoi(in));
        }
        fruits.push_back(f);
    }
    getline(cin,in);
    num_bin=stoi(in);
    for(int i=0;i<num_bin;i++)
    {
        GradBinHyperWeight g;
        getline(cin,in);
        g.featureIdx=stoi(in);
        getline(cin,in);
        g.gradSlider=stof(in);
        getline(cin,in);
        g.binThreshold=stoi(in);
        bins.push_back(g);
    }
    sort(fruits,bins,1);
    // for(auto i: fruits)
    // {
    //     cout<<i.name<<endl;
    // }
    // cout<<endl;
    // for(auto i:bins)
    // {
    //     cout<<i.featureIdx<<endl; 
    // }
    
    return 0;
}

