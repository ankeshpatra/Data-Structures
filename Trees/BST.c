#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

Node *create(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main()
{
    int choice, n, key;
    Node *root = NULL;
    Node *found;
    do
    {
        printf("1. Create Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search a given element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int data;
                printf("Enter the element: ");
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the element to be searched: ");
            scanf("%d", &key);
            found = search(root, key);
            if (found != NULL)
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
