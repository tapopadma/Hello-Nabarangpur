#include<bits/stdc++.h>
using namespace std;
int a[9][9],sz;
vector<pair<int,int> >blank;
bool is_match(int d,int r,int c){
    for(int i=0;i<9;++i)
        if(a[i][c] == d) return true;
    for(int j=0;j<9;++j)
        if(a[r][j] == d) return true;
    int lx = r-r%3,ly = c-c%3;
    for(int i=lx;i<lx+3;++i)
        for(int j=ly;j<ly+3;++j)
            if(a[i][j] == d)
                return true;
    return false;
}
bool ok(int ii){
    int x,y;
    if(ii >= sz ) return true;
    x = blank[ii].first;y=blank[ii].second;
    for(int i=1;i<=9;++i){
        if(!is_match(i,x,y)){
            a[x][y] = i;
            if(ok(ii+1)) return true;
            a[x][y] = 0;//backtracking
        }
    }
    return false;
}
void solve_sudoku(){
    if(ok(0)){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }
        return;
    }
    puts("Oops!");
}
int main(){
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j){
            cin>>a[i][j];
            if(!a[i][j]) blank.push_back(make_pair(i,j));
        }
    sz = blank.size();
    solve_sudoku();
}
