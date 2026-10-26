#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 10;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 20;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 30;
    root->left->left = (struct node *)malloc(sizeof(struct node));
    root->left->left->data = 50;
    root->left->right = (struct node *)malloc(sizeof(struct node));
    root->left->right->data = 50;
    root->right->left = (struct node *)malloc(sizeof(struct node));
    root->right->left->data = 60;
    root->right->right = (struct node *)malloc(sizeof(struct node));
    root->right->right->data = 60;
    printf("Root Node = %d\n", root->data);
    printf("left Node = %d\n", root->left->data);
    printf("Right Node = %d\n", root->right->data);
    printf("Left left Node = %d\n", root->left->left->data);
    printf("Left right Node = %d\n", root->left->right->data);
    printf("right left Node = %d\n", root->right->left->data);
    printf("right right Node = %d\n", root->right->right->data);
    return 0;
}
