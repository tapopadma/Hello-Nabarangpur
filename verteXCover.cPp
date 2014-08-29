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
int ans = 0;
vi adj[100005];
int deg[100005]={0};
void dfs(int node){
    if(deg[node] != 1) return;
    int sz = adj[node].size(),ad;
    for(int i=0;i<sz;++i) {
        if(deg[adj[node][i]] > 0) ad = adj[node][i];
    }
    deg[ad] = 0;++ans;
    sz = adj[ad].size();
    for(int i=0;i<sz;++i){
        if(--deg[adj[ad][i]] > 0) {
            dfs(adj[ad][i]);
        }
    }
}
int main(){
    int n;
    sfd(n);
    for(int i = 1;i<n;++i){
        int x,y;
        sfd(x);
        sfd(y);
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    for(int i=1;i<=n;++i){
        if(deg[i] == 1){
            dfs(i);
        }
    }
    pfd(ans);el;
    return 0;
}
