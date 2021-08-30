logic @Saurabh Kumar...

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node *head;
    head =NULL;
    struct Node *temp;
    temp =(struct Node *)malloc(sizeof(struct Node));
    struct Node *aptr,*bptr;
    aptr =a;
    bptr =b;
    if(aptr == NULL && bptr == NULL){
        temp->next =NULL;
    }
    else if(aptr==NULL && bptr!=NULL ){
        temp->next=bptr;
    }
    else if(bptr == NULL && aptr!=NULL){
        temp->next = aptr;
        
    }
    else{
    merge(aptr,bptr);
    }
    head =temp;
    return head;
}
void merge(struct Node *aptr ,struct Node *bptr){
               while( aptr != NULL and bptr != NULL){
                   if(aptr->data < bptr->data){
                   push(&(temp->next),aptr->data);
                   aptr =aptr->next;
                   }
                   push(&(temp->next),bptr->data);
                   bptr =bptr->link;
               }
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
