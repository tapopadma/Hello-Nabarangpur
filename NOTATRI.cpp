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
    int n;
    while(1){
        sfd(n);
        if(!n) break;
        int a[n];
        for(int i=0;i<n;++i)
            sfd(a[i]);
        sort(a,a+n);
        ll ans = 0;
        for(int i=0;i<=n-3;++i){
            for(int j=i+1;j<=n-2;++j){
                int l = i + 2 , r = n - 1 , m , s = a[i] + a[j] ;
                while(l <= r){
                    m = (l+r)/2;
                    if(a[m] <= s) l = m + 1;
                    else {
                        if(m == l || a[m-1] <= s) {
                                ans += (n-1)-m+1;
                                break;
                        }
                        else r = m - 1;
                    }
                }
            }
        }
        pfld(ans);el;
    }
    return 0;
}

