#include <bits/stdc++.h>
using namespace std;

struct Node{ int k; Node*l{},*r{}; explicit Node(int x):k(x){} };
class BST{ Node*root=nullptr;
    Node*ins(Node*n,int k){ if(!n) return new Node(k); k<n->k? n->l=ins(n->l,k): n->r=ins(n->r,k); return n; }
    Node*minN(Node*n){ return n->l? minN(n->l):n; }
    Node*del(Node*n,int k){ if(!n) return nullptr; if(k<n->k) n->l=del(n->l,k); else if(k>n->k) n->r=del(n->r,k); else{
        if(!n->l||!n->r){ Node*t=n->l?n->l:n->r; delete n; return t; }
        Node*s=minN(n->r); n->k=s->k; n->r=del(n->r,s->k);} return n; }
    int h(Node*n)const{ return n?1+max(h(n->l),h(n->r)):0; }
    void clr(Node*n){ if(!n) return; clr(n->l); clr(n->r); delete n; }
public: ~BST(){ clr(root);} void Insert(int k){ root=ins(root,k);} void Delete(int k){ root=del(root,k);} int Height()const{ return h(root);} };

int main(){ BST T; int keys[]={50,20,75,10,30,60,80}; for(int k:keys) T.Insert(k);
    cout<<"Height (init): "<<T.Height()<<'\n'; T.Delete(50);
    cout<<"Height (after delete 50): "<<T.Height()<<'\n'; }
