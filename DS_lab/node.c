#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertbegg(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void deletebeg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("linked list is empty: \n");
        return;

        temp = head;
        head = head->next;
        free(temp);
        }
    printf("No deleted form begg: \n");
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    printf("Linked list");
    while (temp != NULL)
    {
        printf(" %d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    insertbegg(10);
    insertbegg(20);
    insertbegg(30);
    printf("Before deletion\n");
    display();
    deletebeg();
    printf("After deletion\n");
    display();
    return 0;
}