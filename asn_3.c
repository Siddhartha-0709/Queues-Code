#include<stdio.h>
#define MAX 10
typedef struct 
{
    int array_even[MAX];
    int array_odd[MAX];
    int rear_even;
    int rear_odd;
}queue;
//FULL EMPTY Implement.
void init(queue *q)
{
    q->rear_even=-1;
    q->rear_odd=-1;
}
int EvenisFULL(queue *q)
{
    if(q->rear_even==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int OddisFULL(queue *q)
{
    if(q->rear_odd==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *q, int v)
{
    if(v%2==0)
    {
        if(!EvenisFULL(&q))
        {
            q->rear_even++;
            q->array_even[q->rear_even]=v;
        }
        else
        {
            q->rear_odd++;
            q->array_odd[q->rear_odd]=v;
        }
    }
    else if(v%2!=0)
    {
        if(!OddisFULL(&q))
        {
            q->rear_odd++;
            q->array_odd[q->rear_odd]=v;
        }
        else
        {
            q->rear_even++;
            q->array_even[q->rear_even]=v;
        }
    }
}
void dequeue(queue *q)
{
    if(q->rear_even>q->rear_odd)
    {
        printf("Deleted Value from Even Array- %d", q->array_even[q->rear_even]);
        q->rear_even--;
        for(int i = 0;i <= q->rear_even; i++)
        {
            q->array_even[i]=q->array_even[i+1];
        }
    }
    else if(q->rear_even<q->rear_odd)
    {
        printf("Deleted Value from Odd Array- %d", q->array_odd[q->rear_odd]);
        q->rear_odd--;
        for(int i = 0;i <= q->rear_odd; i++)
        {
            q->array_odd[i]=q->array_odd[i+1];
        }
    }
}
int main()
{
   queue q;
   init(&q);
   enqueue(&q,10);
   enqueue(&q,11);
   enqueue(&q,12);
   enqueue(&q,13);
   enqueue(&q,14);
   enqueue(&q,15);
   enqueue(&q,16);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);
   return 0;
}