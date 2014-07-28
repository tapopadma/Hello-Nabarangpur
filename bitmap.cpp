#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#define Min(a,b)((a<b)?a:b)
#define Max(a,b)((a>b)?a:b)
#define Swap(a,b)(a=b+a-(b=a))
#define sfd(d) scanf("%d",&d)
#define pfd(d) printf("%d",d)
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define pb push_back
#define INFN 123456789
using namespace std;

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int r,c,t;
int ans[183][183];
queue<pair<int,int> >Q;
char bm[183][183];

void bfs(){
    while(!Q.empty()){
        int x = Q.front().first,y = Q.front().second;
        Q.pop();
        for(int i = 0;i < 4;++i){
            int xx = x + X[i] , yy = y + Y[i];
            if(xx >=0 and xx < r and yy >=0 and yy < c){
                if(ans[xx][yy] > ans[x][y] + 1){
                    Q.push(make_pair(xx,yy));
                    ans[xx][yy] = ans[x][y] + 1;
                }
            }
        }
    }
}

int main(){
    sfd(t);
    while(t--){
        sfd(r);sfd(c);
        for(int i=0;i<r;++i){
            for(int j = 0;j<c;++j){
                cin>>bm[i][j];
                if(bm[i][j] == '1') {
                        ans[i][j] = 0;
                        Q.push(make_pair(i,j));
                }
                else ans[i][j] = INFN;
            }
        }
        bfs();
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                pfd(ans[i][j]),sp;
            }
            el;
        }
    }
}
