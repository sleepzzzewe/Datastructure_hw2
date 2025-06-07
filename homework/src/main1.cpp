#include <bits/stdc++.h>
using namespace std;

/* ---------- 抽象 ADT ---------- */
template<class T> struct MaxPQ{virtual ~MaxPQ()=default;virtual bool IsEmpty()const=0;virtual const T&Top()const=0;virtual void Push(const T&)=0;virtual void Pop()=0;};
template<class T> struct MinPQ{virtual ~MinPQ()=default;virtual bool IsEmpty()const=0;virtual const T&Top()const=0;virtual void Push(const T&)=0;virtual void Pop()=0;};

/* ---------- MaxHeap ---------- */
template<class T> class MaxHeap:public MaxPQ<T>{ vector<T>h;
    void up(size_t i){ while(i){ size_t p=(i-1)/2; if(h[p]<h[i]) swap(h[p],h[i]), i=p; else break; }}
    void dn(size_t i){ size_t n=h.size(); while(2*i+1<n){ size_t l=2*i+1,r=l+1,b=i; if(h[l]>h[b]) b=l; if(r<n&&h[r]>h[b]) b=r; if(b!=i){ swap(h[i],h[b]); i=b;} else break; }}
public: bool IsEmpty()const override{return h.empty();}
    const T&Top()const override{ if(h.empty()) throw runtime_error("empty"); return h[0]; }
    void Push(const T&v)override{ h.push_back(v); up(h.size()-1);} 
    void Pop()override{ if(h.empty()) return; h[0]=h.back(); h.pop_back(); if(!h.empty()) dn(0);} };

/* ---------- MinHeap ---------- */
template<class T> class MinHeap:public MinPQ<T>{ vector<T>h;
    void up(size_t i){ while(i){ size_t p=(i-1)/2; if(h[i]<h[p]) swap(h[i],h[p]), i=p; else break; }}
    void dn(size_t i){ size_t n=h.size(); while(2*i+1<n){ size_t l=2*i+1,r=l+1,s=i; if(h[l]<h[s]) s=l; if(r<n&&h[r]<h[s]) s=r; if(s!=i){ swap(h[i],h[s]); i=s;} else break; }}
public: bool IsEmpty()const override{return h.empty();}
    const T&Top()const override{ if(h.empty()) throw runtime_error("empty"); return h[0]; }
    void Push(const T&v)override{ h.push_back(v); up(h.size()-1);} 
    void Pop()override{ if(h.empty()) return; h[0]=h.back(); h.pop_back(); if(!h.empty()) dn(0);} };

int main(){ int arr[]={7,3,9,1,5,2,8}; MaxHeap<int> mx; MinHeap<int> mn;
    for(int x:arr){ mx.Push(x); mn.Push(x);} 
    cout<<"MaxHeap:"; while(!mx.IsEmpty()){ cout<<' '<<mx.Top(); mx.Pop(); }
    cout<<"\nMinHeap:"; while(!mn.IsEmpty()){ cout<<' '<<mn.Top(); mn.Pop(); }
    cout<<'\n'; }

/*******************************************************
