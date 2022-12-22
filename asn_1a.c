#include <stdio.h>
//Queue using Array
#define size 100
typedef struct
{
    int rear;
    int queue[size];
} queue;
void init(queue *q)
{
    q->rear = -1;
}
void enqueue(queue *q, int v)
{
    if (q->rear == size - 1)
    {
        printf("Queue is Full!");
        return;
    }
    else
    {
        q->rear++;
        q->queue[q->rear] = v;
        printf("Insterted in Queue-%d\n",v);
    }
}
int dequeue(queue *q)
{
    if (q->rear == -1)
    {
        printf("Queue is Empty!");
    }
    else
    {
        int x = q->queue[0];
        for(int i=0;i<q->rear;i++)
        {
            q->queue[i]=q->queue[i+1];
        }
        q->rear--;
        return x;
    }
}
int main()
{
    queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    int x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    x= dequeue(&q);
    printf("Deleted Value- %d\n", x);
    dequeue(&q);

    return 0;
}