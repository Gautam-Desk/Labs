#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;

};
struct node*head=NULL;
void insertbeg(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;

}
void display(){
    struct node*temp=head;
    if(head == NULL){
        printf("Link list is empty: \n");
        return;
    }
    printf("link list: ");
    while(temp!=NULL){
        printf("%d ==> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");   
}
int main(){
    insertbeg(30);
    insertbeg(5-1);
    insertbeg(10);
    display();
    return 0;
}