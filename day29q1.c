Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,k,i;
    scanf("%d",&n);

    struct node *head=NULL,*temp=NULL,*newnode,*prev=NULL;

    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
            head=newnode;
        else
            prev->next=newnode;

        prev=newnode;
    }

    scanf("%d",&k);

    struct node *last=head;
    while(last->next!=NULL)
        last=last->next;

    last->next=head;

    int steps=n-k;
    temp=head;

    for(i=1;i<steps;i++)
        temp=temp->next;

    head=temp->next;
    temp->next=NULL;

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
