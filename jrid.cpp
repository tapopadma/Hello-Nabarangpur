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
int main(){
    int T,t=0;
    sfd(T);
    while(t < T) {
        int n;
        sfd(n);--n;
        int a[n];
        for(int i=0;i<n;++i)
            sfd(a[i]);
        int x = 0,y,meh=0,msf=0,lx,ry,ln=0;
        for(int i=0;i<n;++i) {
            y = i;
            meh += a[i];
            if(meh < 0) meh = 0,x = i+1;
            if(meh > msf) {
                msf = meh;
                lx = x , ry = y ,ln = y-x+1;
            }
            else if(meh == msf) {
                if(y-x+1 > ln) {
                    ln = y - x + 1;
                    lx = x , ry = y ;
                }
            }
        }
        if(msf) {
            printf("The nicest part of route %d is between stops %d and %d\n",++t,lx+1,ry+2);
        }
        else {
            printf("Route %d has no nice parts\n",++t);
        }
    }
    return 0;
}
