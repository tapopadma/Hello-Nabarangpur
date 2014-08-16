#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define sfd(k) scanf("%d",&k)
#define Swap(a,b) a = b + a - (b= a)
#define Min(a,b) (a<b ? a : b)
#define Max(a,b) (a>b ? a : b)
#define all(v) (v.begin(),v.end())
using namespace std;
struct box{
    int h,w,d;
};
bool order(const box &x,const box &y){
    return (x.w * x.d > y.w * y.d);
}
int main(){
    int n;
    while(sfd(n)&&n){
        int tot  =  0,x,y,z;
        vector<box>b;
        int a[3];
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j) sfd(a[j]);
            sort(a,a+3);
            do{
                box var;
                var.h = a[0] , var.w = a[1] , var.d = a[2];
                b.push_back(var);
            }while(next_permutation(a,a+3));
        }
        sort(b.begin(),b.end(),order);
        tot = b.size();
        int ans[tot];
        for(int i=0;i<tot;++i)
            ans[i] = b[i].h;
            int res = 0;
        for(int i=0;i<tot;++i){
            for(int j=0;j<i;++j){
                if(b[j].w > b[i].w && b[j].d > b[i].d && ans[i] < ans[j] + b[i].h){
                    ans[i] = ans[j] + b[i].h;
                }
            }
            res = Max(res,ans[i]);
        }
    //for(int i=0;i<tot;++i)cout<<b[i].h<<' '<<b[i].w<<' '<<b[i].d<<'\n';
        printf("%d\n",res);
    }
    return 0;
}

