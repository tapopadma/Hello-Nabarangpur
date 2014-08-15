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
ll bm[1<<21];
int n;
int a[21][21];
int main(){
    int t;
    sfd(t);
    while(t--){
        sfd(n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                sfd(a[i][j]);
        bm[(1<<n)-1]=1;
        for(int mask = (1<<n)-2;mask>=0;--mask){
            int row = 0;
            for(int i=0;i<n;row += (mask>>i)&1 ,++i);
            bm[mask] = 0;
            for(int col = 0;col < n;++col){
                if((mask&(1<<col)) == 0 && a[row][col]==1){
                    bm[mask] += bm[mask|(1<<col)];
                }
            }
        }
        pfld(bm[0]);el;
    }
    return 0;
}
