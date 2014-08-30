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
#define all(a) a.begin(),a.end()
using namespace std;
int  main() {
    int t;
    sfd(t);
    while(t--) {
        int n1,n2;
        sfd(n1);
        sfd(n2);
        int m;
        sfd(m);
        int v1[m],v2[m],w[m];
        for(int i=0;i<m;++i){
            sfd(v1[i]);
            sfd(v2[i]);
            sfd(w[i]);
        }
        int dp[m+1][n1+1][n2+1];
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n1;++j) {
                for(int k=0;k<=n2;++k) {
                    if(j<=0 && k<=0) {
                        dp[i][j][k] = 0;
                    }
                    else if(!i) {
                        dp[i][j][k] = INF;
                    }
                    else {
                        int x = j - v1[i-1];
                        if(x < 0) x = 0;
                        int y = k - v2[i-1];
                        if(y < 0) y = 0;
                        dp[i][j][k] = Min(dp[i-1][x][y]+w[i-1],dp[i-1][j][k]);
                    }
                }
            }
        }
        pfd(dp[m][n1][n2]);el;
    }
    return 0;
}
