//Citation: Code with Harry
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
    //struct Node *next2;
};
void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Value: %d\n", ptr->val);
        ptr = ptr->next;
    }
}
struct Node * Endinsert(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->val = val;
    struct Node * p = head;
    struct Node *p1=(struct Node *) malloc(sizeof(struct Node));
    //struct Node *pn = second;

    while(p->next!=NULL){
        p1=p;
        p = p->next;
    }
    p->next = ptr;
    p1->next->next=ptr;
    ptr->next = NULL;
    return head;
    
}
struct Node * Firstinsert(struct Node *head, int val){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->val=val;
    ptr->next->next=head->next;


    return ptr;
}

struct Node * Indexinsert(struct node *head,int data,int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->val=val;
    p->next->next=ptr->next;
    

} 
struct Node * Firstdelete(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    //Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    //Linking nodes
    head->data=7;
    head->next=second;
    head->next->next=third;
    second->data=11;
    second->next=third;
    second->next->next=fourth;
    third->data=21;
    third->next=fourth;
    third->next->next=NULL;
    fourth->data=12;
    fourth->next=NULL;
    //fourth->next->next=NULL;
    Traverse(head);
    //head=insertAtFirst(head,56);
    //linkedListTraversal(head);
    //insertAtIndex(head,56,4);
    //linkedListTraversal(head);
    printf("After:\n");
    head=Firstdelete(head);
    Traverse(head);


}
