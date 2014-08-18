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
/* This code mightn't be very clear to the reader bcz of random variable names :P */
struct node{
    ll sum;
    ll ls;
    ll rs;
    ll best;
}tree[200005];
int q[50002],pos,val;
node combineBoth(node lf,node rg){
    node ret;
    ret.sum = lf.sum + rg.sum;
    ret.ls = Max(lf.ls,lf.sum+rg.ls);
    ret.rs = Max(rg.rs,rg.sum+lf.rs);
    ret.best = Max(Max(lf.best,rg.best),lf.rs+rg.ls);
    return ret;
}
node build(int l,int r,int i){
    if(l == r) {
        tree[i].best = tree[i].ls = tree[i].rs = tree[i].sum = q[l];
        return tree[i];
    }
    int m = (l+r)/2;
    node lf = build(l,m,i<<1);
    node rg = build(1+m,r,1+(i<<1));
    return (tree[i] = combineBoth(lf,rg));
}
node ans(int l,int r,int a,int b,int i){
    if(l==a && r== b){
        return tree[i];
    }
    int m = (l+r)/2;
    if(b <= m){
        return ans(l,m,a,b,(i<<1));
    }
    if(a > m){
        return ans(1+m,r,a,b,1+(i<<1));
    }
    node lf = ans(l,m,a,m,(i<<1));
    node rg = ans(1+m,r,1+m,b,1+(i<<1));
    return combineBoth(lf,rg);
}
node update(int l,int r,int i){
    if(l == r) {
        if(l == pos) /*this is always true :D :p */
            tree[i].best = tree[i].ls = tree[i].rs = tree[i].sum = val;
        return tree[i];
    }
    int m = (l+r)/2;
    node lf=tree[i<<1],rg=tree[1+(i<<1)];
    if(pos <= m)
        lf = update(l,m,i<<1);
    else
        rg = update(1+m,r,1+(i<<1));
    return (tree[i] = combineBoth(lf,rg));
}
int main(){
    int n;
    sfd(n);
    for(int i=1;i<=n;++i)
        sfd(q[i]);
    build(1,n,1);
    int m;
    sfd(m);
    while(m--){
        bool x;
        cin>>x;
        sfd(pos);
        sfd(val);
        if(x)
            pfld(ans(1,n,pos,val,1).best),el;
        else
            update(1,n,1);
    }
    return 0;
}
