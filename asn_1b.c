#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void enqueue(struct node **head, int v)
{
    struct node *curr, *ptr;
    curr= malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("No Space in Heap/Queue");
        return;
    }
    printf("Inserted Value- %d\n",v);
    curr->data= v;
    curr->next=NULL;
    if(*head==NULL)
    {
        *head= curr;
        ptr=curr;
    }
    else
    {
        *head= curr;
        curr->next=ptr;
        ptr=curr;
    }
}
void dequeue(struct node **head)
{
    struct node *ptr= *head;
    if(*head==NULL)
    {
        printf("Underflow");
        return;
    }
    *head= ptr->next;
    printf("Deleted Value - %d\n", ptr->data);
    free(ptr);
}
void display(struct node *head)
{
    struct node *ptr= head;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
   struct node *queue=NULL;
   enqueue(&queue,10); 
   enqueue(&queue,20); 
   enqueue(&queue,30); 
   enqueue(&queue,40); 
   enqueue(&queue,50); 
   enqueue(&queue,60);
   dequeue(&queue);
   dequeue(&queue);
   dequeue(&queue);
   display(queue); 
   return 0;
}