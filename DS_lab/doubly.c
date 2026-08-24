#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;

};
void insertbrg(struct node **head, int value){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=*head;

    if (*head !=NULL){
        (*head)->prev=newnode;
    }
    *head=newnode;
}
void display(struct node *head){
    struct node *temp=head;
    printf("Display the nodes\n ");
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head = NULL;
    insertbrg(&head, 30);
    insertbrg(&head, 40);
    insertbrg(&head, 110);
    insertbrg(&head, 70);
    insertbrg(&head, 90);

    display(head);
    return 0;
}