/// fleury algorithm is used to get a euler path of a graph



#include<bits/stdc++.h>
using namespace std;
#define sz 1000

bool graph[sz][sz];
int nodes,edges;
int degree[sz];
vector <pair<int,int> > eular_path;
bool visited[sz];
int cnt = 0;

void dfs(int u)
{
    visited[u] = true;

    for(int v=0;v<nodes;v++)
    {
        if(graph[u][v] && !visited[v])
        {
            cnt++;
            dfs(v);
        }
    }
}

bool isBridge(int u,int v)
{
    dfs(u);
    int before = cnt;
    memset(visited,false,sizeof(visited));
    cnt = 0;

    graph[u][v] = false;
    graph[v][u] = false;

    dfs(u);
    int after = cnt;
    memset(visited,false,sizeof(visited));
    cnt = 0;

    graph[u][v] = true;
    graph[v][u] = true;

    return after<before;
}

void doEularTraverse(int u)
{
    if(eular_path.size()==edges)
        return;

    int bridge;

    for(int v=0; v<nodes; v++)
    {
        if(!graph[u][v])
            continue;

        if(isBridge(u,v))
            bridge = v;
        else
        {
            graph[u][v] = false;
            graph[v][u] = false;
            eular_path.push_back({u,v});
            doEularTraverse(v);
            return;
        }
    }

    graph[u][bridge] = false;
    graph[bridge][u] = false;
    eular_path.push_back({u,bridge});
    doEularTraverse(bridge);
    return;
}

int getSource()
{
    int odd = 0;
    int src = 0;

    for(int i=0; i<nodes; i++)
    {
        if(degree[i]%2)
        {
            odd++;
            src = i;
        }
    }

    if(odd==0 || odd==2)
        return src;
    else
        return -1;
}

void findEularPath()
{
    int src = getSource();

    if(src==-1)
        cout<<"no eular path"<<endl;
    else
        doEularTraverse(src);
}

int main()
{
    cin>>nodes>>edges;

    for(int i=0; i<edges; i++)
    {

        int u,v;
        cin>>u>>v;
        graph[u][v] = true;
        graph[v][u] = true;
        degree[u]++;
        degree[v]++;
    }

    findEularPath();

    cout<<"Eular Path : "<<endl;

    for(int i=0;i<eular_path.size();i++)
        cout<<eular_path[i].first<<" "<<eular_path[i].second<<endl;
}
