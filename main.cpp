#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=82000;
vector<int> adj[N];
map<int,string> st;
map<string,int> id;
map<pair<int,int>,int> exist;
pair<int,int> f[N];
bool child[N];
pair<int,int> mut[N];
int num_mut=0;


void getmut(int node)
{
    bool ch=0;
    for(int i=0; i<adj[node].size(); i++)
    {
        if(child[adj[node][i]])
        {
            mut[node].first++;
            mut[node].second=node;
            ch=1;
        }
    }
    if(ch)num_mut++;
}


int where(int rat)
{
    int lo=0,hi=num_mut-1,ans=rat,val=mut[rat].first;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(mut[mid].first<val)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
            ans=mid;
        }
    }
    return ans;
}


void fri(int node)
{
    memset(child,0,sizeof child);
    memset(mut,0,sizeof mut);
    num_mut=0;
    for(int i=0; i<adj[node].size(); i++)
    {
        child[adj[node][i]]=1;
    }
    for(int i=1; i<N; i++)
    {
        if(!child[i]&&i!=node)
        {
            getmut(i);
        }
    }
    if(num_mut==0)
    {
        cout<<"No Followers Yet.\nRecommended Top Influncer.\n";
        for(int i=0; i<10&&f[i].first; i++)
        {
            if(f[i].second==node)continue;
            cout<<st[f[i].second]<<" "<<f[i].first<<endl;
        }
        cout<<endl;
    }
    else
    {
        sort(mut,mut+N,greater<pair<int,int> >());
        int rat=max(num_mut*5/100,min(10,num_mut));
        int to=where(rat);
        cout<<"Number of Recomende Friends : "<<to+1<<" Threshold Mutual Ratio : "<<mut[to].first<<endl;
        for(int i=0; i<=to; i++)
        {
            cout<<st[mut[i].second]<<"   "<<mut[i].first<<endl;
        }
    }
}
int main()
{
    
    return 0;
}
