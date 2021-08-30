//logic @SAURABH KUMAR.....

#include<stdio.h>
///node template
struct node{
  int data;
  struct node *link;
};
struct node *head;
//inert at begnining
void insert_beg(struct node *head,int data){
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));
    tmep->data =data;
    temp->link =NULL;
    if(head !=NULL){
        head = temp;
    }
    else{
        temp->link =head;
        head =temp;
    }
}
///insert at last of link list
void insert_last(struct node *head ,int data){
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data =data;
    temp->link =NULL;
    if(head ==NULL){
        head =temp;
    }
    else{
        struct node *p;
        p=head;
        while(p->link !=NULL){
            p =p->link;
        }
        p->link =temp;
    }
}
//iterative 
void reverse_link(strut node *head){
    struct node *prev=NULL;
    struct node *curr =head;
    struct node *next =NULL;
    while(curr !=NULL){
        next =curr->link;
        curr->link =prev;
        prev =curr;
        curr =next;
    }
    head =prev;    
}
//only print the values in reverse order
void reverse_print(struct node *p){
    if(p == NULL){
        return;
    }
    reverse_print(p->link);
    printf("Reverse_link_data :",p->data);
}
//reverse list using recurssion
void reverse_recurssion(struct node *p){
    if(p->link ==NULL){
        head =p;
        return;
    }
    reverse_recurssion(p->link);
    struct node *q =p->link;
    q->link =p;
    p->link =NULL;
}
///length recursive
int get_length(struct node *head){
    if(head ==NULL){
        return 0;
    }
    return 1+get_length(*head->link);
}
//length iterative
int get_len(struct node *head){
    int count =0;
    struct node *curr =head;
    while(curr->link !=NULL){
        count=count+1;
    }
    return count
}
///search elememt
bool search(struct node *head ,int search_data){
    struct node *curr =head;
    while(curr !=NULL){
        if(curr->data == search_data){
            printf("DATA FOUND(address): %d",curr);
            return TRUE;
        }
        curr =curr->link;
    }
    return FALSE;
    printf("DATA NOT FOUND");
}

