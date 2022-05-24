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



int main()
{
    
    return 0;
}
