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
char b[3][3];
bool f(char c){
    for(int i=0;i<3;++i){
        bool n = 1;
        for(int j=0;j<3;++j) if(b[i][j]!=c) {n=0;break;}
        if(n) return 1;
    }
    for(int j=0;j<3;++j){
        bool n = 1;
        for(int i=0;i<3;++i) if(b[i][j]!=c) {n=0;break;}
        if(n) return 1;
    }
    bool n = 1;
    for(int i=0;i<3;++i) if(b[i][i]!=c) {n=0;break;}
    if(n) return 1;
    n = 1;
    for(int i=0;i<3;++i) if(b[i][3-i-1]!=c) {n=0;break;}
    return n;
}
int main(){
    while(1){
        int nx = 0 , no = 0 ;
        bool wx , wo;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cin>>b[i][j] , nx += (b[i][j]=='X') , no += (b[i][j]=='O');
                if(b[i][j]=='e') return 0;
            }
        }
        if(nx-no == 1 or nx-no == 0){
            wx = f('X');
            wo = f('O');
            if(wx&wo) puts("invalid");
            else if(wx){
                puts(((nx==no)?"invalid":"valid"));
            }
            else if(wo){
                puts(((nx==no)?"valid":"invalid"));
            }
            else puts((nx+no==9)?"valid":"invalid");
        }
        else puts("invalid");
    }
}
