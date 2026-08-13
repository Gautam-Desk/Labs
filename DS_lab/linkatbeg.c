#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertbeg(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Link list is empty: \n");
        return;
    }
    printf("link list: ");
    while (temp != NULL)
    {
        printf("%d ==> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    // trial run: insert nodes at the beginning of the linked list
    insertbeg(30);
    insertbeg(20);
    insertbeg(10);

    display();
    return 0;
}

// explanation:
// This program inserts nodes at the beginning of the list using insertbeg().
// Each new node becomes the new head, so the final list order is reversed
// compared to the insertion order.
// Expected output:
// link list: 10 ==> 20 ==> 30 ==> NULL
