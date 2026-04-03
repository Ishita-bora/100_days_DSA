#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

int postIndex;

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    int rootValue = postorder[postIndex--];
    struct Node* root = newNode(rootValue);

    int index = findIndex(inorder, start, end, rootValue);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, index + 1, end);
    root->left = buildTree(inorder, postorder, start, index - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}