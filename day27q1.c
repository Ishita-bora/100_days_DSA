#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }
    return head;
}

int length(struct node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    struct node *head1 = create(n);

    scanf("%d", &m);
    struct node *head2 = create(m);

    int l1 = length(head1);
    int l2 = length(head2);

    struct node *p1 = head1;
    struct node *p2 = head2;

    int diff = abs(l1 - l2);

    if(l1 > l2)
        for(int i = 0; i < diff; i++) p1 = p1->next;
    else
        for(int i = 0; i < diff; i++) p2 = p2->next;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data == p2->data)
        {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}