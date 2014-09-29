/* Status : 0.62 second on spoj */
/* Author : tapopadma tripathy 
for any inconvenience send mail to tapopadmatripathy1995@gmail.com*/
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
#define T(x) strtok(x, " \n\r\t")
using namespace std;
const int M = 1e6+5;
int mn[M] , mx[M] ,cnt[M];
int smn,smx;
void addmn(int key) {
    mn[smn++] = key;
    int i = smn - 1;
    while(i> 1 && mn[i] < mn[i/2]) {
        Swap(mn[i],mn[i/2]);i/=2;
    }
}
void addmx(int key) {
    mx[smx++] = key;
    int i = smx - 1;
    while(i > 1 && mx[i] > mx[i/2]) {
        Swap(mx[i],mx[i/2]);i/=2;
    }
}
void removmn() {
    int key = mn[--smn];
    mn[1]  =  key;
    int i = 1;
    while(2*i < smn) {
        if(2*i+1 >= smn) {
            if(mn[i] > mn[2*i]) {
                Swap(mn[i],mn[2*i]);
            }
            break;
        }
        if(mn[i] > mn[2*i] || mn[i] > mn[2*i+1]) {
            if(mn[2*i] < mn[2*i+1]){
                Swap(mn[i],mn[2*i]);i = 2*i;
            }
            else {
                Swap(mn[i],mn[2*i+1]);i = 2*i+1;
            }
        }
        else break;
    }
}
void removmx() {
    int key = mx[--smx];
    mx[1]  =  key;
    int i = 1;
    while(2*i < smx) {
        if(2*i+1 >= smx) {
            if(mx[i] < mx[2*i]) {
                Swap(mx[i],mx[2*i]);
            }
            break;
        }
        if(mx[i] < mx[2*i] || mx[i] < mx[2*i+1]) {
            if(mx[2*i] > mx[2*i+1]){
                Swap(mx[i],mx[2*i]);i = 2*i;
            }
            else {
                Swap(mx[i],mx[2*i+1]);i = 2*i+1;
            }
        }
        else break;
    }
}
int main(){
    int n;
    ll ans = 0;
    smn = smx = 1;
    sfd(n);
    Fill(cnt,0);
    for(;n--;) {
        int k;
        sfd(k);
        while(k--){
            int x;
            sfd(x);
            addmn(x);
            addmx(x);
            cnt[x] += 2;
        }
        while(!cnt[mn[1]]) {
            removmn();
        }
        while(!cnt[mx[1]]) {
            removmx();
        }
        ans += mx[1]-mn[1];
        cnt[mx[1]] -= 2;
        cnt[mn[1]] -= 2;
        removmn();
        removmx();
    }
    pfld(ans);el;
    return 0;
}
