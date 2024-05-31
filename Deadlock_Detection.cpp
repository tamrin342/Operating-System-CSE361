#include<bits/stdc++.h>
using namespace std;

void dfs(vector<set<int>> &adj, int s, vector<int> &visited, int alpha, vector<int> &stck)
{
    int pos;
    stck.push_back(s);
    visited[s]= 0;

    for(int x : adj[s])
    {
        if(visited[x]==-1)
            dfs(adj,x,visited,alpha,stck);
        if(visited[x]==0)
        {
            cout<<"Cycle --> ";
            for(int i2=0; i2<stck.size(); i2++)
            {
                if(stck[i2]==x)
                    pos=i2;
            }
            for(int i=pos; i<stck.size(); i++)
            {
                 if(alpha==0)
    cout<<stck[i]<<" ";
    else if(alpha==1) cout<< char(stck[i]+'A')<<" ";
    else cout<< char(stck[i]+'a')<<" ";
            }
              cout<<endl;
        }
    }
    visited[s]=1;
}

int main(){
    int n,e,u=0,v=0,alpha=0;
    char a1,a2;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>e;
    vector<set<int>> adj(n+1+26);

    cout<<"Enter each edge as a pair of nodes :"<<endl;
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
         else{
            u= a1-'0';
            v=a2-'0';
         }
        adj[u].insert(v);
    }

    vector<int> visited(n+26,-1);
    vector<int> stck;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==-1 || visited[i]==0)
        {
            dfs(adj,i,visited,alpha,stck);
        }
    }
    return 0;
}
