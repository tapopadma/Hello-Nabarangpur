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
struct node{
    ll sum;
    ll ls;
    ll rs;
    ll best;
}binarytree[200002];
int arr[50002];
node combineBoth(node myleft,node myright){
    ll myleftsum = myleft.ls;
    myleftsum = Max(myleftsum,myleft.sum + myright.ls);
    ll myrightsum = myright.rs;
    myrightsum = Max(myrightsum,myright.sum+myleft.rs);
    ll mybest = Max(myleft.rs+myright.ls,Max(myleft.best,myright.best));
    ll mysum  = myleft.sum + myright.sum;
    node t;
    t.best = mybest;
    t.sum = mysum;
    t.ls = myleftsum;
    t.rs = myrightsum;
    return t;
}
node make_tree(int l,int r,int i){
    if(l==r){
        binarytree[i].best = binarytree[i].ls = binarytree[i].rs = binarytree[i].sum = arr[l];
        return binarytree[i];
    }
    int m = (l+r)/2;
    node myleft = make_tree(l,m,(i<<1));
    node myright = make_tree(m+1,r,(i<<1)+1);
    return (binarytree[i]=combineBoth(myleft,myright));
}
node solve(int i,int l,int r,int a,int b){
    if(l==a && r==b){
        return binarytree[i];
    }
    int m = (l+r)/2;
    if(b <= m) {
        return solve((i<<1),l,m,a,b);
    }
    if(a > m){
        return solve(1+(i<<1),1+m,r,a,b);
    }
    node myleft = solve((i<<1),l,m,a,m);
    node myright = solve(1+(i<<1),1+m,r,1+m,b);
    return combineBoth(myleft,myright);
}
int main(){
    int no;
    sfd(no);
    for(int i=1;i<=no;++i)
        sfd(arr[i]);
    make_tree(1,no,1);
    int query;
    sfd(query);
    while(query--){
        int a,b;
        sfd(a);
        sfd(b);
        pfld(solve(1,1,no,a,b).best);el;
    }
    return 0;
}

