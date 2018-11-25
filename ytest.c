#include<stdio.h>
#include<stdlib.h>
#define xheight 32
#include"avl.h"
#include"xfast.h"

void yfins(struct nlf *rt,int x){       //well test and implement now and later put that w/2 and w limits
    struct lf *t,*q;int i,j,k,st;
    t=xsucc3(rt,x);
    if(t==NULL)if((q=xpred(rt,x))!=NULL&&q->n<(xheight/2))
    {xinsert(rt,x);t=xfind(rt,x);t->root=insertNode(q->root,x,&st);t->n=getsize(t->root);xdel(rt,q->x);return;}
    //printf("succ found:%p\n",t);printf("succ %d:%d\n",x,t==NULL?-1:t->x);
    st=0;//printf("succ %d:%d\n",x,t==NULL?-1:t->x);
    if(t==NULL){xinsert(rt,x);return;}
    else t->root=insertNode(t->root,x,&st);
    if(st)t->n++;printf("st:%d,%d,%d\n",x,t->n,st);
    if(t->n>=xheight){printf("limit exceeded:%d\n",t->n);
        k=t->root->value;
        xinsert(rt,k);
        q=xfind(rt,k);
        q->root=t->root->left;
        q->root=insertNode(q->root,k,&st);
        q->n=getsize(q->root);
        t->root=t->root->right;
        t->n=getsize(t->root);
    }
}

void yfdel(struct nlf *rt,int x){
    struct lf *t,*q;int i,j,k,st;struct avl_node *e;
    t=xsucc3(rt,x);
    if(t==NULL)return;
    if(t->x==x){
        if(t->n==1){xdel(rt,x);free((void*)t->root);}
        k=avl_max(t->root);
        xinsert(rt,k);q=xfind(rt,k);
        q->root=deleteNode(t->root,k,&st);
        }
    else{
        t->root=deleteNode(t->root,k,&st);
        if(st)t->n--;
    }
}

int yfsucc(struct nlf *rt,int x){
    struct lf *t,*q;int i,j,k,st;
    if(rt==NULL)return -1;
    t=xsucc(rt,x);
    if(t==NULL)return -1;
    return avl_succ(t->root,x);
}

int yfpred(struct nlf *rt,int x){
    struct lf *t,*q;int i,j,k,st;
    if(rt==NULL)return -1;
    t=xsucc(rt,x);
    if(t==NULL){
    q=xpred(rt,x);
    if(q==NULL)return -1;
    return avl_max(t->root);
    }
    i=avl_pred(t->root,x);
    if(i==-1){
    q=xpred(rt,x);
    if(q==NULL)return -1;
    return avl_max(t->root);
    }
    return i;
}

int yffind(struct nlf *rt,int x){
    struct lf *t;int i,j;
    t=xsucc3(rt,x);
    if(t==NULL)return 0;
    return avl_find(t->root,x);
}

int main(){
    int i,j,n;struct nlf *st,stm;struct lf *a;
    st=&stm;
    stm.l.l=stm.r.l=NULL;stm.lv=xheight;stm.p=NULL;stm.tl=stm.tr=0;
    scanf("%d",&n);printf("n:%d\n",n);
    for(i=0;i<n;i++){scanf("%d",&j);printf("inserting:%d\n",j);yfins(st,j);
    }
    return 0;
}