#include<stdio.h>
#include<stdlib.h>
#define xheight 32
#include"avl.h"
#include"xfast.h"



int main(){
    int i,j,n;struct nlf *st,stm;struct lf *a;
    st=&stm;
    stm.l.l=stm.r.l=NULL;stm.lv=xheight;stm.p=NULL;stm.tl=stm.tr=0;
    scanf("%d",&n);printf("n:%d\n",n);
    for(i=0;i<n;i++){scanf("%d",&j);printf("inserting:%d\n",j);xinsert(st,j);printf("finding xmin\n");
    //a=xmin(st);printf("found!\n");while(a!=NULL){printf("%d,",a->x);a=a->r;}
    }
    a=xmin(st);printf("found!\n");while(a!=NULL){printf("%d,",a->x);a=a->r;}
    return 0;
}