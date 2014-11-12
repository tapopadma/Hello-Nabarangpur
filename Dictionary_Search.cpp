#include<bits/stdc++.h>// Concept of Ternary Search Tree
using namespace std;
struct TST{
    char data;
    bool ie;
    TST *l,*e,*r;
};
TST *G(char c){
    TST *p = new TST;p->data= c;
    p->l=p->e=p->r=NULL;p->ie = 0;
    return p;
}
void print(TST *root,char *ch,int sz){
    if(!root) return;
    print(root->l,ch,sz);
    ch[sz] = root->data;
    if(root->ie){
       ch[sz+1] = '\0' ;cout<<ch<<'\n';
    }
    print(root->e,ch,sz+1);
    print(root->r,ch,sz);
}
TST *In(TST *root,char *s){
    if(!root){
        root = G(*s);
    }
    if(root->data < *s) root->r = In(root->r,s);
    else if(root->data > *s) root->l = In(root->l,s);
    else {
        if(*(s+1)) {
            root->e = In(root->e,s+1);
        }
        else root->ie = 1;
    }
    return root;
}
int main(){
    TST *root = NULL,*ret=NULL;
    cout<<"Enter no of words in the dictionary to be built:";
    int n;cin>>n;
    while(n--){
        char s[100];
        cout<<"word:";
        cin>>s;
        root = In(root,s);
    }
    char ch[100];
    cout<<"The dictionary has:\n";
    print(root,ch,0);bool b=0;
    while(1){
        char s[100];
        cout<<"Search:";cin>>s;
        vector<char>v;v.clear();
        TST *rt = root;int i=0;
        while(rt){
            if(rt->data < s[i]) rt = rt->r;
            else if(rt->data > s[i]) rt = rt->l;
            else{
                b = rt->ie;
                rt = rt->e;++i;
                if(i== strlen(s)) {
                    char ch[100];
                    strcpy(ch,s);
                    if(b) cout<<ch<<"\n";
                    print(rt,ch,strlen(s));
                    break;
                }
            }
        }
    }
}
