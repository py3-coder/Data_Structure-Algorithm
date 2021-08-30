@Saurabh Kumar
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};
void insert_beg(struct node **root,int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    ///printf("Enter node data");
    ///scanf("%d",&temp->data);
    temp->data =data;
    temp->link =NULL;
    if(*root == NULL){
        *root = temp;
    }
    else{
        temp->link =*root;
        *root =temp;
    }
}
void printList(struct node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->link;
    }
}
int main(){
struct node *root =NULL;
insert_beg(&root ,4);
insert_beg(&root ,5);
insert_beg(&root ,7);
printList(root);
return 0;
}
