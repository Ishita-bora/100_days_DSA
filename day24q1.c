Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) 
{
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) 
{
    struct Node* merged = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) 
    {
        struct Node* newNode;

        if (l1->data < l2->data) 
        {
            newNode = createNode(l1->data);
            l1 = l1->next;
        } else 
        {
            newNode = createNode(l2->data);
            l2 = l2->next;
        }

        if (merged == NULL) 
        {
            merged = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (l1 != NULL)
     {
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while (l2 != NULL) 
    {
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

    return merged;
}

void printList(struct Node* head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() 
{
    int n, m, x;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    struct Node* mergedList = mergeLists(list1, list2);

    printList(mergedList);

    return 0;
}
