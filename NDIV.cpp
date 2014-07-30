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
using namespace std;
#define M 32000
int prime[3435],sz=0;
bool p[M]={0};
void sieve(){
    prime[sz++] = 2;
    for(int i=3;i<=M;i+=2){
        if(!p[i]){
            prime[sz++] = i;
            for(int j=1;j*i<=M;++j){
                p[i*j] = 1;
            }
        }
    }
}
int main(){
    sieve();
    int a, b , n;
    sfd(a);
    sfd(b);
    sfd(n);
    int ans = 0;
    for(int i=a;i<=b;++i){  /*O(1e4)*/
        int cnt = 1,num = i;
        for(int j=0,pr=prime[j];j < sz && pr*pr<=num;pr = prime[++j]){
            if(num%pr == 0){
                int dv = 0;
                while(num%pr == 0){
                    ++dv;num /= pr;
                }
                cnt *= (dv+1);
            }
        }
        if(num > 1) cnt <<=1;
        //cout<<i<<' '<<cnt;el;
        if(cnt == n) ++ans;
    }
    pfd(ans);el;
    return 0;
}

