#include<iostream>
#include<cstdio>
#include<cstring>
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
#define T(x) strtok(x, " \n\r\t")
using namespace std;
struct sq{int d,s;};
bool f(int x,int y,int r,int c) {return (x >= 0&&y>=0&&x<r&&y<c);}
int main(){
    int r,c,cnt=0;
    while(sfd(r),sfd(c)&&r&&c) {
        char ch[r][c];
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                cin>>ch[i][j];
        sq dp[r][c];
        bool ok = 0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j) {
                dp[i][j].d = 1;
                if(ch[i][j]=='A')
                    dp[i][j].s=0,ok=1;
                else
                    dp[i][j].s = -1;
            }
        }
        if(!ok){
            printf("Case %d: 0\n",++cnt);continue;
        }
        for(int cycle=1;cycle<=100;++cycle) {
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j) {
                    if(!f(i,j-1,r,c)) continue;
                    if(dp[i][j].d < dp[i][j-1].d+1 && ch[i][j]==ch[i][j-1]+1) {
                        dp[i][j].d = dp[i][j-1].d+1;
                        dp[i][j].s = dp[i][j-1].s;
                    }
                }
            }
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j) {
                    if(!f(i-1,j-1,r,c)) continue;
                    if(dp[i][j].d < dp[i-1][j-1].d+1&& ch[i][j]==ch[i-1][j-1]+1) {
                        dp[i][j].d = dp[i-1][j-1].d+1;
                        dp[i][j].s = dp[i-1][j-1].s;
                    }
                }
            }
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j) {
                    if(!f(i-1,j,r,c)) continue;
                    if(dp[i][j].d < dp[i-1][j].d+1&& ch[i][j]==ch[i-1][j]+1) {
                        dp[i][j].d = dp[i-1][j].d+1;
                        dp[i][j].s = dp[i-1][j].s;
                    }
                }
            }
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j) {
                    if(!f(i-1,j+1,r,c)) continue;
                    if(dp[i][j].d < dp[i-1][j+1].d+1&& ch[i][j]==ch[i-1][j+1]+1) {
                        dp[i][j].d = dp[i-1][j+1].d+1;
                        dp[i][j].s = dp[i-1][j+1].s;
                    }
                }
            }
            for(int i=r-1;i>=0;--i){
                for(int j=c-1;j>=0;--j) {
                    if(!f(i,j+1,r,c)) continue;
                    if(dp[i][j].d < dp[i][j+1].d+1&& ch[i][j]==ch[i][j+1]+1) {
                        dp[i][j].d = dp[i][j+1].d+1;
                        dp[i][j].s = dp[i][j+1].s;
                    }
                }
            }
            for(int i=r-1;i>=0;--i){
                for(int j=c-1;j>=0;--j) {
                    if(!f(i+1,j+1,r,c)) continue;
                    if(dp[i][j].d < dp[i+1][j+1].d+1&& ch[i][j]==ch[i+1][j+1]+1) {
                        dp[i][j].d = dp[i+1][j+1].d+1;
                        dp[i][j].s = dp[i+1][j+1].s;
                    }
                }
            }
            for(int i=r-1;i>=0;--i){
                for(int j=c-1;j>=0;--j) {
                    if(!f(i+1,j,r,c)) continue;
                    if(dp[i][j].d < dp[i+1][j].d+1&& ch[i][j]==ch[i+1][j]+1) {
                        dp[i][j].d = dp[i+1][j].d+1;
                        dp[i][j].s = dp[i+1][j].s;
                    }
                }
            }
            for(int i=r-1;i>=0;--i){
                for(int j=c-1;j>=0;--j) {
                    if(!f(i+1,j-1,r,c)) continue;
                    if(dp[i][j].d < dp[i+1][j-1].d+1&& ch[i][j]==ch[i+1][j-1]+1) {
                        dp[i][j].d = dp[i+1][j-1].d+1;
                        dp[i][j].s = dp[i+1][j-1].s;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                 if(dp[i][j].s==0){
                    ans = Max(ans,dp[i][j].d);
                }
            }
        }
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
