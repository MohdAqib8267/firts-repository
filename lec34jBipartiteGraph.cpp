#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    bool bipart=true;
    vector<vector<int>>adj;
    vector<bool>vis;
    vector<int>col;
void colour(int node,int curr){
    if(col[node]!=-1 && col[node]!=curr){
        bipart=false;
        return;
    }
    col[node]=curr;
    if(vis[node]){
        return;
    }
    vis[node]=true;
    for(auto i: adj[node]){
        
        colour(i, curr xor 1);
    }
}
int main(){
    int n,m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,false);
    col=vector<int>(n,-1);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            colour(i,0);
        }
    }
    if(bipart){
        cout<<"graph is a bipartite graph"<<endl;
    }
    else{
        cout<<"graph is not bipartite"<<endl;
    }
    return 0;
}