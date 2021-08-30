@Saurabh_Kumar
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    char colour;
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
void insert_fixup(struct node **root , struct node *z){
    while(z !=(*root) && z !=(*root)->l && z !=(*root)->r && z->p->colour != 'R'){
        struct node *y;
        ///p(z) left child of p(p(z)
        if(z->p && z->p->p && z->p == z->p->p->l){
            y=z->p->p->r;
            if(!y){
                z=z->p->p;
            }
            //uncle red (y = red ) case1
            else if(y->colour == 'R'){
            y->colour ='B';
            z->p->colour='B';
            z->p->p->colour ='R';
            z =z->p->p;
            }
            ///case2
            else if(y->colour =='B' && z==z->p->r){
                z = z->p;
                left_rotate(root, z);
                //case3
                z->p->colour ='B';
                z->p->p->colour ='R';
                right_rotate(root ,z->p->p);
            }
        }
        else{
            y=z->p->p->l;
            if(!y){
                z=z->p->p;
            }
            //uncle red (y = red ) case1
            else if(y->colour == 'R'){
            y->colour ='B';
            z->p->colour='B';
            z->p->p->colour ='R';
            z =z->p->p;
            }
            ///case2
            else if(y->colour =='B' && z==z->p->l){
                z =z->p;
                right_rotate(root, z);
                //case3
                z->p->colour ='B';
                z->p->p->colour ='R';
                left_rotate(root ,z->p->p);
            }
        }
    }
    (*root)->colour = 'B';
}
void insert(struct node **root ,int data){
    struct node *z =(struct node*)malloc(sizeof(struct node));
    z->data = data;
    z->l = z->r =NULL;
    if(*root == NULL){
        z->colour ='B';
        (*root) = z;
    }
    else {
        struct node *y =NULL;
        struct node *x =(*root);
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->l;
            else
                x = x->r;
        }
        z->p = y;
        if (z->data > y->data)
            y->r = z;
        else
            y->l = z;
        z->colour = 'R';
        insert_fixup(root,z);
    }
}
void in_order(struct node *root){
    if(root == NULL){
        return;
    }
    in_order(root->l);
    printf("%d" , root->data);
    in_order(root->r);
}
void pre_order(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d" , root->data);
    pre_order(root->l);
    pre_order(root->r);
}
void post_order(struct node *root){
    if(root == NULL){
        return;
    }
    post_order(root->l);
    post_order(root->r);
    printf("%d" , root->data);
}int main()
{
    struct node *root = NULL;
    insert(&root,10);
    insert(&root,20);
    insert(&root,40);
    insert(&root,30);
    insert(&root,50);
    insert(&root,35);
    insert(&root,25);
    insert(&root,37);
    printf("inorder Traversal Is : ");
    in_order(root);
    printf("preorder Traversal Is : ");
    pre_order(root);
    printf("postorder Traversal Is : ");
    post_order(root);
    return 0;
}
