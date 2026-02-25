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

struct Node* deleteFirstOccurrence(struct Node* head, int key) 
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key)
     {
        head = temp->next;
        free(temp);
        return head;
    }

    
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp != NULL)
     {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() 
{
    int n, x, key;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printList(head);

    return 0;
}c
