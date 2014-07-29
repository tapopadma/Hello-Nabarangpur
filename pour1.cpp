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
int main(){
    int t;
    sfd(t);
    while(t--){
        int a  ,b , c , ans;
        sfd(a);
        sfd(b);
        sfd(c);
        if((c > a && c > b) || c%gcd(a,b) ) puts("-1");
        else if(c == a || c == b) puts("1");
        else if(!c) puts("0");
        else {
            if( a < b) Swap(a,b);
            int p = 0 , q = 0;
            int cnt = 1;p = a;
            while(p || q){
                if(p == 0) p = a;
                else {
                    int need = b - q;
                    if(need == 0) q = 0;
                    else {
                        if(need > p){
                            q += p;p=0;
                        }
                        else {
                            p -= need;
                            q += need;
                        }
                    }
                }
                ++cnt;
                if(p == c || q == c) {ans = cnt ;break;}
            }
            p = 0 , q = 0;
            cnt = 1;q = b;
            while(p || q){
                if(q == 0) q = b;
                else {
                    int need = a - p;
                    if(need == 0) p = 0;
                    else {
                        if(need > q){
                            p += q;
                            q = 0;
                        }
                        else {
                            q -= need;
                            p += need;
                        }
                    }
                }
                ++cnt;
                if(p == c || q == c) {ans = Min(ans,cnt) ;break;}
            }
            pfd(ans);el;
        }
    }
}

