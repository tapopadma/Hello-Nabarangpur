#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<cmath>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#define pi pair<int,int>
#define ppi pair<int,pair<int,int> >
#define pip pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define mp make_pair
#define Min(a,b)((a<b)?a:b)
#define Max(a,b)((a>b)?a:b)
#define Swap(a,b)(a=b+a-(b=a))
#define sfd(d) scanf("%d",&d)
#define sfld(d) scanf("%lld",&d)
#define sff(d) scanf("%f",&d)
#define sfc(ch) scanf("%c",&ch)
#define sfs(s) scanf("%s",s)
#define pfd(d) printf("%d",d)
#define pfld(d) printf("%lld",d)
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define pb push_back
#define ppb pop_back
#define INF 123456789
#define mod 1000000007
#define ll long long int
#define si short int
#define gcd __gcd
#define T(x) strtok(x, " \n\r\t")
#define all(a) a.begin(),a.end()
using namespace std;
vi adj[2001];
si color[2001];
bool bipartite(int src) {
    int sz = adj[src].size();
    bool ret = 1;
    for(int i=0;i<sz;++i) {
        int ad = adj[src][i];
        if(color[src] == color[ad])
            return 0;
        if(color[ad] == -1) {
            color[ad] = 1 - color[src];
            ret &= bipartite(ad);
        }
    }
    return ret;
}
int main(){
    int t,c=0;
    sfd(t);
    while(t--) {
        int n,m,x,y;
        sfd(n);
        sfd(m);
        for(int i=0;i<n+2;++i)
            adj[i].clear();
        for(int i=0;i<m;++i){
            sfd(x);
            sfd(y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i=0;i<2001;++i)
            color[i] = -1;
        bool ok;
        for(int i=1;i<=n;++i) {
            if(color[i] == -1){
                color[i] = 0;
                ok  =  bipartite(i);
                if(!ok) break;
            }
        }
        //for(int i=1;i<=n;++i) cout<<"color of node "<<i<<" : "<<color[i]<<'\n';
        printf("Scenario #%d:\n",++c);
        puts((!ok)?"Suspicious bugs found!":"No suspicious bugs found!");
    }
    return 0;
}
