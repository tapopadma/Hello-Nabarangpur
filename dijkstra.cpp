#include<bits/stdc++.h>
using namespace std;
struct edge{
    int vertex,weight;
}var,heap[10000];
vector<edge>adj[1000];
int dis[1000],n,m,mxsz=0,sr;
void Insert_heap(edge E){
    heap[mxsz++] = E;
    for(int i=mxsz-1;i && dis[heap[i].vertex] < dis[heap[i/2].vertex];swap(heap[i],heap[i/2]),i/=2);
}
void Delete(){
    --mxsz;
    swap(heap[0],heap[mxsz]);
    for(int i=0;2*i < mxsz;){
        int child = dis[heap[2*i].vertex];
        if(1+2*i < mxsz){
            child = min(child,dis[heap[1+2*i].vertex]);
        }
        if(child < dis[heap[i].vertex]){
            if(child == dis[heap[2*i].vertex]){
                swap(heap[i],heap[2*i]);
                i *= 2;
            }
            else {
                swap(heap[i],heap[1+2*i]);
                i = 2*i+1;
            }
        }
        else break;
    }
}
void dijkstra(int src){
    for(int i=0;i<=n;++i)
        dis[i] = 123123123;
    dis[src] = 0;
    for(int times=1;times<n;times++){ // o n
        int sz = adj[src].size();
        for(int i=0;i<sz;++i){
            int ad = adj[src][i].vertex;
            int d = adj[src][i].weight + dis[src];
            if(dis[ad] > d){
                dis[ad] = d;
                Insert_heap(adj[src][i]);  // o log n
            }
        }
        src = heap[0].vertex;
        Delete();// o log n
    }
    for(int i=1;i<=n;++i)
        cout<<i<<" is "<<dis[i]<<" far from "<<sr<<"\n";
}
int main(){
    cout<<"no of nodes:";
    cin>>n;
    cout<<"enter no of edges:";
    cin>>m;
    for(int i=0;i<m;++i){
        int x,y,z;
        cin>>x>>var.vertex>>var.weight;
        adj[x].push_back(var);
    }
    cout<<"source : ";cin>>sr;
    dijkstra(sr);
    return 0;
}
