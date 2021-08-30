@Saurabh Kumar
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int colour;
    struct node *p;
    struct node *l;
    struct node *r;
};
void left_rotate(struct node **root, struct node *x){
    if(!x || !x->r){
        return;
    }
    struct node *y = x->r;
    x->r = y->l;
    if(x->r != NULL){
        x->r->p =x;
        y->p= x->p;
    }
    if(x->p ==  NULL){
        (*root) = y;
    }
    if(x == x->p->l){
        y =x->p->l;
    }
    else{
        y= x->p->r;
    }
    y->l =x;
    x->p =y;
}
void right_rotate(struct node **root, struct node *x){
    if(!x || !x->r){
        return;
    }
    struct node *y = x->l;
    x->l = y->r;
    if(x->l != NULL){
        x->l->p =x;
        y->p= x->p;
    }
    if(x->p ==  NULL){
        (*root) = y;
    }
    if(x == x->p->l){
        y =x->p->l;
    }
    else{
        y= x->p->r;
    }
    y->r =x;
    x->p =y;
}
void delete_fixup(struct node **root,struct node *x){
    
}
