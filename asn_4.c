#include <stdio.h>
typedef struct
{
    int q1[5];
    int r1;
    int q2[5];
    int r2;
    int q3[5];
    int r3;
} queue;
void init(queue *q)
{
    q->r1 = -1;
    q->r2 = -1;
    q->r3 = -1;
}
void enqueue(queue *q, int v)
{
    if (q->r1 < 4)
    {
        q->r1++;
        q->q1[q->r1] = v;
        printf("Inserting Element- %d in Queue - Q1-%d\n", v, q->r1);
    }
    else if (q->r2 < 4)
    {
        q->r2++;
        q->q2[q->r2] = v;
        printf("Inserting Element- %d in Queue - Q2-%d\n", v, q->r2);
    }
    else if (q->r3 < 4)
    {
        q->r3++;
        q->q3[q->r3] = v;
        printf("Inserting Element- %d in Queue - Q3-%d\n", v, q->r3);
    }
    else
    {
        printf("NO SPACE IN QUEUE\n");
    }
}
void dequeue(queue *q)
{
    if (q->r1 == -1)
    {
        printf("Everything Empty\n");
        return;
    }
    else
    {
        if ((q->r1 <= 4) && (q->r2 == -1) && (q->r3 == -1))
        {
            printf("Deleting Element- %d\n", q->q1[0]);
            for (int i = 0; i < q->r1; i++)
            {
                q->q1[i] = q->q1[i + 1];
            }
            q->r1--;
        }
        else if ((q->r2 != -1) || (q->r3 != -1))
        {
            printf("Deleting Element- %d\n", q->q1[0]);
            for (int i = 0; i < q->r1; i++)
            {
                q->q1[i] = q->q1[i + 1];
            }

            if (q->r2 > -1)
            {
                q->q1[q->r1] = q->q2[0];
                for (int i = 0; i < q->r2; i++)
                {
                    q->q2[i] = q->q2[i + 1];
                }
                if (q->r3 > -1)
                {
                    q->q2[q->r2] = q->q3[0];
                    for (int i = 0; i < q->r3; i++)
                    {
                        q->q3[i] = q->q3[i + 1];
                    }
                    q->r3--;
                }
                else
                {
                    q->r2--;
                }
            }
            else
            {
                q->r1--;
            }
        }
    }
}
int main()
{
    int n;
    queue q;
    init(&q);

    // while(n!=0)
    // {
    //     int ch;
    //     printf("Enter 1 to Enqueue and 2 to Dequeue--\n");
    //     scanf("%d",&ch);
    //     switch(ch)
    //     {
    //         case 1:
    //         printf("Enter Value to Enqueue--\n");
    //         int v;
    //         scanf("%d", &v);
    //         enqueue(&q,v);
    //         break;
    //         case 2:
    //         dequeue(&q);
    //         break;
    //     }
    //     printf("Do you wish to Continue? \n");
    //     scanf("%d",&n);
    // }
    for (int i = 0; i < 17; i++)
    {
        enqueue(&q, i);
    }
    printf("\nDeleting\n");
    printf("\nDisplaying Q1 Top- %d \n", q.r1);
    printf("\nDisplaying Q2 Top- %d \n", q.r2);
    printf("\nDisplaying Q3 Top- %d \n\n\n", q.r3);

    for (int i = 0; i < 17; i++)
    {
        dequeue(&q);
        // printf("\nDisplaying Q1 Top- %d \n", q.r1);
        // printf("\nDisplaying Q2 Top- %d \n", q.r2);
        // printf("\nDisplaying Q3 Top- %d \n\n\n", q.r3);
    }
    return 0;
}