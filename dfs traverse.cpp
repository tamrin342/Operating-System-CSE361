#include<bits/stdc++.h>
using namespace std;

void dfsrec(vector<int> adj[], int s, vector<bool> &visited, int alpha)
{
    visited[s]= true;
    if(alpha==0)
    cout<<s<<" ";
    else if(alpha==1) cout<< char(s+65)<<" ";
    else cout<< char(s+97)<<" ";
    for(int x : adj[s])
    {
        if(visited[x]==false)
            dfsrec(adj,x,visited,alpha);
    }
}
void dfs(vector<int> adj[], int v, int flag, int alpha)
{
    vector<bool> visited(v+1,false);
    if(flag==0){
    for(int i=1; i<v; i++)
    {
        if(visited[i]==false)
        {
            dfsrec(adj,i,visited,alpha);
        }
    }
    }

     else {
    for(int i=0; i<v; i++)
    {
        if(visited[i]==false)
        {
            dfsrec(adj,i,visited,alpha);
        }
    }
    }
}


int main(){
    int n,e,flag=0,u=0,v=0,alpha=0;
    char  a1,a2;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>e;
    vector<int> adj[n+1];

    for(int i=0; i<e; i++)
    {
        cin>>a1>>a2;

       if(a1>=65 && a1<=90)
            {
            u=a1 - 65;
            v= a2- 65;
            alpha=1;
            }
        else if(a1>=97 && a1<=122)
            {
            u= a1 - 97;
            v= a2- 97;
            alpha=2;
            }

        if(u==0 || v==0) flag=1;
        adj[u].push_back(v);
    }

    dfs(adj,n,flag,alpha);
    return 0;
}
