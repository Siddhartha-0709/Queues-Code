#include <stdio.h>
#define MAX 16

typedef struct
{
    int data[MAX];
    int size;

    int q1_top;
    int q2_top;
    int q3_top;
    int q4_top;

    int q1_rear;
    int q2_rear;
    int q3_rear;
    int q4_rear;
} queue;
void init(queue *q)
{
    q->q1_top = -1;
    q->q2_top = 3;
    q->q3_top = 7;
    q->q4_top = 11;

    q->q1_rear = -1;
    q->q2_rear = 3;
    q->q3_rear = 7;
    q->q4_rear = 11;
    q->size = 16;

    for(int i=0;i<MAX;i++)
    {
        q->data[i]=0;
    }
}
void enqueue(queue *q, int v, int postn)
{
    if (postn == 1)
    {
        printf("Enter Type of Insertion in Position-1 ?");
        int type;
        scanf("%d", &type);
        if ((q->q1_top == -1) && (q->q1_rear == -1))
        {
            q->q1_top++;
            q->q1_rear++;
            q->data[q->q1_rear] = v;
        }
        else if (q->q1_top == (q->q1_rear + 1) % q->size)
        {
            printf("No Space in Given Position");
        }
        else
        {
            if (type == 0) // Front Side Insertion
            {
                printf("Front Side Inserted\n");
                q->q1_top = (q->q1_top + 4 - 1) % 4;
                q->data[q->q1_top] = v;
            }
            else // Rear Side Insertion
            {
                printf("Rear Side Inserted\n");
                q->q1_rear = (q->q1_rear + 1) % 4;
                q->data[q->q1_rear] = v;
            }
        }
    }
    else if (postn == 2)
    {
        printf("Enter Type of Insertion in Position-2 ?");
        int type;
        scanf("%d", &type);
        if ((q->q2_top == 3) && (q->q2_rear == 3)) // Empty Queue
        {
            q->q2_top++;
            q->q2_rear++;
            q->data[q->q2_rear] = v;
        }
        else if (type == 0) // Front Side Insertion
        {
            q->q2_top = (q->q2_top + q->size - 1) % q->size;
            if (q->q2_top == 3)
            {
                q->q2_top = 7;
            }
            if (q->q2_top == q->q2_rear)
            {
                printf("No Space in Entered Position");
                q->q2_top = 4;
            }
            else
            {
                q->data[q->q2_top] = v;
            }
        }
        else if (type == 1) // Rear Side Insertion
        {
            q->q2_rear = (q->q2_rear + 1) % q->size;
            if (q->q2_rear == 0)
            {
                q->q2_rear = 4;
            }
            if (q->q2_top == q->q2_rear)
            {
                printf("No Space in Entered Position");
                q->q2_rear = 7;
            }
            else
            {
                q->data[q->q2_rear] = v;
            }
        }
    }
    else if (postn == 3)
    {
        printf("Enter Type of Insertion in Position-3 ?");
        int type;
        scanf("%d", &type);
        if ((q->q3_top == 7) && (q->q3_rear == 7))
        {
            q->q3_top++;
            q->q3_rear++;
            q->data[q->q3_rear] = v;
        }
        else if (type == 0) // Front Side Insertion
        {
            q->q3_top = (q->q3_top + q->size - 1) % q->size;
            printf("Q3 top- %d\n",q->q3_top);
            if (q->q3_top == 7)
            {
                q->q3_top = 11;
            }
            if (q->q3_top == q->q3_rear)
            {
                printf("No Space in Entered Position");
                q->q3_top = 8;
            }
            else
            {
                q->data[q->q3_top] = v;
            }
        }
        else if (type == 1) // Rear Side Insertion
        {
            q->q3_rear = (q->q3_rear + 1) % q->size;
            if (q->q3_rear == 0)
            {
                q->q3_rear = 8;
            }
            if (q->q3_top == q->q3_rear)
            {
                printf("No Space in Entered Position");
                q->q3_rear = 11;
            }
            else
            {
                q->data[q->q3_rear] = v;
            }
        }
    }
    else if (postn == 4)
    {
        printf("Enter Type of Insertion in Position-4 ?");
        int type;
        scanf("%d", &type);
        if ((q->q4_top == 11) && (q->q4_rear == 11))
        {
            q->q4_top++;
            q->q4_rear++;
            q->data[q->q4_rear] = v;
        }
        else if (type == 0) // Front Side Insertion
        {
            q->q4_top = (q->q4_top + q->size - 1) % q->size;
            if (q->q4_top == 11)
            {
                q->q4_top = 15;
            }
            if (q->q4_top == q->q4_rear)
            {
                printf("No Space in Entered Position");
                q->q4_top = 12;
            }
            else
            {
                q->data[q->q4_top] = v;
            }
        }
        else if (type == 1) // Rear Side Insertion
        {
            q->q4_rear = (q->q4_rear + 1) % q->size;
            if (q->q4_rear == 0)
            {
                q->q4_rear = 12;
            }
            if (q->q4_top == q->q4_rear)
            {
                printf("No Space in Entered Position");
                q->q4_rear = 15;
            }
            else
            {
                q->data[q->q4_rear] = v;
            }
        }
    }
    else
    {
        return;
    }
}
void dequeue(queue *q, int postn, int type)
{
    if (postn == 1)
    {
        if(q->q1_top==-1)
        {
            printf("Empty Queue\n");
            return ;
        }
        else if(q->q1_top==q->q1_rear)
        {
            printf("Deleted Element is - %d",q->data[q->q1_top]);
            q->data[q->q1_top]=0;
            q->q1_rear=q->q1_top=-1;
        }
        else if (type==0)//Front Side Deletion
        {
            printf("Deleting Element- %d",q->data[q->q1_top]);
            q->data[q->q1_top]=0;
            q->q1_top=(q->q1_top+1)%4;
        }
        else if(type==1)//Rear Side Deletion
        {
            printf("Deleting Element- %d",q->data[q->q1_rear]);
            q->data[q->q1_rear]=0;
            q->q1_rear=(q->q1_rear+3)%4;
        }
    }
    else if (postn == 2)
    {
        if(q->q2_top==3)
        {
            printf("Empty Queue\n");
            return ;
        }
        else if(q->q2_top==q->q2_rear)
        {
            printf("Deleted Element is - %d",q->data[q->q2_top]);
            q->data[q->q2_top]=0;
            q->q2_rear=q->q2_top=3;
        }
        else if(type==0)//Front Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q2_top]);
            q->data[q->q2_top]=0;
            q->q2_top=(q->q2_top+1)%q->size;
            if(q->q2_top==8)
            {
                q->q2_top=4;
            }
        }
        else if(type==1)//Rear Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q2_top]);
            q->data[q->q2_top]=0;
            q->q2_rear=(q->q2_rear+q->size-1)%q->size;
            if(q->q2_rear==3)
            {
                q->q2_rear=7;
            }
        }
    }
    else if (postn == 3)
    {
        if(q->q3_top==7)
        {
            printf("Empty Queue\n");
            return;
        }
        else if(q->q3_top==q->q3_rear)
        {
            printf("Deleted Element is - %d",q->data[q->q3_top]);
            q->q3_rear=q->q3_top=-1;
        }
        else if(type==0)//Front Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q3_top]);
            q->data[q->q3_top]=0;
            q->q3_top=(q->q3_top+1)%q->size;
            if(q->q3_top==11)
            {
                q->q3_top=8;
            }
        }
        else if(type==1)//Rear Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q3_top]);
            q->data[q->q3_top]=0;
            q->q3_rear=(q->q3_rear+q->size-1)%q->size;
            if(q->q3_rear==7)
            {
                q->q3_rear=11;
            }
        }
    }
    else if (postn == 4)
    {
        if(q->q1_top==11)
        {
            printf("Empty Queue\n");
            return ;
        }
        else if(q->q4_top==q->q4_rear)
        {
            printf("Deleted Element is - %d",q->data[q->q4_top]);
            q->q4_rear=q->q4_top=-1;
        }
        else if(type==0)//Front Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q4_top]);
            q->data[q->q4_top]=0;
            q->q4_top=(q->q4_top+1)%q->size;
            if(q->q4_top==0)
            {
                q->q4_top=12;
            }
        }
        else if(type==1)//Rear Side Deletion
        {
            printf("Deleted Element is %d", q->data[q->q4_top]);
            q->data[q->q4_top]=0;
            q->q4_rear=(q->q4_rear+q->size-1)%q->size;
            if(q->q4_rear==11)
            {
                q->q4_rear=15;
            }
        }
    }
    else
    {
        return;
    }
}
void display(queue q)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", q.data[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    queue q;
    init(&q);
    while (n != 0)
    {
        printf("Continue?\n");
        scanf("%d", &n);
        printf("Enter Value of Enuqueue?\n");
        int v;
        scanf("%d", &v);
        printf("Enter Position to Enuqueue? \n");
        int pos;
        scanf("%d", &pos);
        enqueue(&q, v, pos);
        display(q);
    }
    n=1;
    while (n != 0)
    {
        printf("Deletion Continue?\n");
        scanf("%d", &n);
        printf("Enter Position to Dequeue? \n");
        int pos;
        scanf("%d", &pos);
        int type;
        printf("Enter Type of Deletion?  ");
        scanf("%d",&type);
        dequeue(&q,pos,type);
        display(q);
    }
    return 0;
}