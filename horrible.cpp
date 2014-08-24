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
#define sfs(s) scanf("%s",s)
#define sfc(c) scanf("%c",&c)
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
ll s[400005],cs[400005];
void update(int i,int l,int r,int p,int q,int v){
    if(p > r or q < l) return;
    if(p<=l && r<=q) {
        s[i] += v;
    }
    else {
        int m = (l+r)>>1;
        int ii = i<<1;
        update(ii,l,m,p,q,v);
        update(1+ii,1+m,r,p,q,v);
        cs[i] = cs[ii]+cs[ii+1]+(m-l+1)*s[ii]+(r-m)*s[1+ii];
    }
}
ll sum(int i,int l,int r,int p,int q) {
    if(p > r or q < l) return 0;
    ll ret = s[i]*(Min(q,r)-Max(p,l)+1);
    if(l >= p and r <= q) {
        ret += cs[i];
    }
    else {
        int ii = i<<1 , m = (l+r)>>1;
        ret += sum(ii,l,m,p,q) + sum(1+ii,1+m,r,p,q);
    }
    return ret;
}
int main(){
    int t,n,c,p,q,v;
    sfd(t);
    while(t--){
            sfd(n);
            sfd(c);
            Fill(s,0);
            Fill(cs,0);
            bool b;
            while(c--){
                cin>>b;
                if(!b){
                    sfd(p);sfd(q);sfd(v);
                    update(1,1,n,p,q,v);
                }
                else {
                    sfd(p);sfd(q);
                    pfld(sum(1,1,n,p,q));el;
                }
            }
    }
    return 0;
}
