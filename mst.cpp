#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class prims
{
    public:
    int spannigtree(int v, vector<vector<pair<int,int>>>adj)
    {

        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>pq;
        vector<bool>Ismst(v,0);
    
        int cost=0;
        pq.push({0,{0,-1}});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second.first;
            pq.pop();
            if(!Ismst[node])
            {
                Ismst[node]=1;
                cost+=wt;

                for(int i=0;i<adj[node].size();i++)
                {
                    int nextnode=adj[node][i].first;
                    int edgeweight=adj[node][i].second;
                    if(!Ismst[nextnode])
                    {
                        pq.push({edgeweight,{nextnode,node}});
                    }
                }
            }
        }
        return cost;
    }   
};
int main()
{
    int V;
    int e;

    cout<<"enter the number of  vertices :";
    cin>>V;
    cout<<"enter the number of edges ";
    cin>>e;

    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    prims obj;
    int count=obj.spannigtree(V,adj);
    cout<<"count is :"<<count;
    return 0;
}